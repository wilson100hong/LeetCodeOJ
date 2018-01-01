/*
 * Understand KMP
 *
 * Trick: buildNext(), j from 0 to n-2 (!)
 *
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> buildNext(const string& pattern) {
        int n = pattern.size();
        vector<int> next(n, 0);
        
        next[0] = -1;
        int k = -1, j = 0;
        while (j < n - 1) {  // FML
            if (k == -1 || pattern[k] == pattern[j]) {
                ++k;
                ++j;
                if (pattern[k] != pattern[j])
                    next[j] = k;
                else 
                    next[j] = next[k];
            } else {
                k = next[k];
            }
        }
        return next;
    }
    
    int strStr(string haystack, string needle) {
        if (needle.size() == 0) return 0;

        int i = 0, j = 0;
        vector<int> next = buildNext(needle);
        
        int nh = haystack.size(), nn = needle.size();
        while (i < nh && j < nn) {
            if (j == -1 || haystack[i] == needle[j]) {
                ++j;
                ++i;
            } else {
                j = next[j];
            }
        }
        
        if (j == needle.size()) {
            return i-j;
        } else {
            return -1;
        }
    }
};

int main() {
    string S, P;
    cout << "S: ";
    cin >> S;
    cout << "P: ";
    cin >> P;

    Solution sol;
    vector<int> next = sol.buildNext(P);
    for (int i : next)
        cout << i << ", ";
    cout << endl;
    cout << sol.strStr(S, P) << endl;
}
