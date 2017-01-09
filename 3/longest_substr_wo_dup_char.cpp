// careful when reset cursor
#include <iostream>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = -1, cur = 0;
        int max_len = 0;
        unordered_map<char, int> pos;
        while (cur < s.size()) {
            char c = s[cur];
            if (pos.count(c) && left < pos[c]) {
                left = pos[c];
                pos.erase(c);
            }
            pos[c] = cur;
            int len = cur - left;
            if (len > max_len) {
                max_len = len;
            }
            cur++;
        }
        return max_len;
    }
};

int main() {
    Solution sol;
    cout << sol.lengthOfLongestSubstring("abba") << endl;
}
