#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    
    string preprocess(const string& s) {
        string r = "#";
        for (char c : s) {
            r = r + c + '#';
        }
        return r;
        
    }
    
    string longestPalindrome(string s) {

        string str = preprocess(s);
        vector<int> p(str.size(), 0);
        
        int center = 0, right = 0;
        int n = p.size();

        for (int i=0;i<n;++i) {
            int i_mirror = 2*center - i;
            if (right > i) {
                p[i] = min(p[i_mirror], right - i);
            } else {
                p[i] = 0;
            }
            while ((i+p[i]+1 < n) 
                   && (i-p[i]-1 >= 0) 
                   && str[i+p[i]+1] == str[i-p[i]-1]) {
                p[i]++;
            }
            if (i + p[i] > right) {
                right = i + p[i];
                center = i;
            }
        }
        
        int maxLen = 0, maxCenter = -1;
        for (int i=0;i<n;++i) {
            if (p[i] > maxLen) {
                maxLen = p[i];
                maxCenter = i;
            }
        }
        return s.substr((maxCenter - maxLen)/2, maxLen);
    }
};

int main() {
    Solution sol;
    cout << sol.longestPalindrome("babad") << endl;
}
