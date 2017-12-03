class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> cnt;
        for (char c : ransomNote) {
            cnt[c]++;
        }
        int rest = cnt.size();
        for (char c : magazine) {
            if (cnt.count(c) && cnt[c] > 0) {
                cnt[c]--;
                if (cnt[c] == 0) rest--;
            }
        }
        return rest == 0;
    }
};
