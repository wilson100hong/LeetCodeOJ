#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        // count
        unordered_map<char, int> cnt;
        for (char c : t) {
            if (cnt.count(c) == 0) {
                cnt[c] = 0;
            }
            cnt[c]++;
        }

        string best = s;
        bool success = false;

        int complete = 0;
        int i = 0, j = 0;
        // window is from s[j] to s[i-1]
        while (1) {
            // advance i until complete
            while (i < s.size() && complete != cnt.size()) {
                char c = s[i];
                if (cnt.count(c)) {
                    cnt[c]--;
                    if (cnt[c] == 0) {
                        complete++;
                    }
                }
                i++;
            }
            
            if (complete != cnt.size()) {
                break;
                // impossible
            }
            success = true;

            while (j < i && complete == cnt.size()) {
                string tmp = s.substr(j, i-j);
                if (tmp.size() < best.size()) {
                    best = tmp;
                }
                char c = s[j];
                if (cnt.count(c)) {
                    cnt[c]++;
                    if (cnt[c] > 0) {
                        complete--;
                    }
                }
                j++;
            }
            // advance j
        }
        return success ? best : "";
    }
};

int main() {
    //string S = "ADOBECODEBANC";
    //string T = "ABC";
    string S = "abc";
    string T = "b";
    Solution sol;
    cout << sol.minWindow(S, T) << endl;

}
