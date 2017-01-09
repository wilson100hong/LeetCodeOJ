#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
// bit manipulation
class Solution {
public:
    int max(int a, int b) {
        return a > b ? a : b;
    }
    int maxProduct(vector<string>& words) {
        unordered_map<int, int> table;
        for (int i=0;i<words.size();++i) {
            // compute hash key
            const string& word = words[i];
            int key = 0;
            for (int j=0;j<word.size();++j) {
                key |= (1<<(word[j]-'a'));
            }
            if (table.count(key) == 0) {
                table[key] = 0;
            }
            table[key] = max(table[key], word.size());
            //cout << word << " " << table[key] << endl;
        }

        int best = 0;
        for (auto& kv1 : table) {
            for (auto& kv2 : table) {
                if ((kv1.first & kv2.first) == 0) {
                    best = max(best, kv1.second * kv2.second);
                }
            }
        }
        return best;
    }
};

int main() {
    vector<string> input = {"abcw","baz","foo","bar","xtfn","abcdef"};
    Solution sol;
    cout << sol.maxProduct(input) << endl;
}
