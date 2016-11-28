class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> cnt(26, 0);
        for (int i=0;i<s.size();++i) {
            cnt[s[i]-'a']++;
        }
        for (int i=0;i<t.size();++i) {
            cnt[t[i]-'a']--;
            if (cnt[t[i]-'a'] < 0) {
                return t[i];
            }
        }
        return 0;
    }
};
