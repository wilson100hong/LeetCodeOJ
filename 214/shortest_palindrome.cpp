#include <iostream>
#include <vector>


using namespace std;


class Solution {
public:
    string reverse(const string& s) {
        string r = s;
        int i=0, j=r.size()-1;
        while (i<j) {
            swap(r[i], r[j]);
            i++;
            j--;
        }
        return r;
    } 
    
    string shortestPalindrome(string s) {
        string m = s + "$" + reverse(s);
    
        vector<int> T(m.size() + 1, 0);  // additional tail for last
        T[0] = -1;
        int k = -1, j = 0;
        while (j < T.size()-1) {
            if (k==-1 || m[k] == m[j]) {
                T[++j] = ++k;
            } else {
                k = T[k];
            }
        }
        
        // pick the longest prefix match
        int maxLen = T[T.size()-1];
        
        return reverse(s.substr(maxLen)) + s;
    }
};

int main() {
    Solution sol;
    cout << sol.shortestPalindrome("aacecaaa") << endl;
    cout << sol.shortestPalindrome("abcd") << endl;

}
