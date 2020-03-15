#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;


class Solution {
public:
  int longestConsecutive(vector<int>& nums) {
    unordered_set<int> dedup;
    unordered_map<int, int> s_map;  // map store "start" of range
    unordered_map<int, int> e_map;  // map store "end" of range

    for (int num : nums) {
      if (dedup.count(num)) continue;
      dedup.insert(num);

      int new_start=num, new_end = num;

      if (s_map.count(num+1)) {
        new_end = s_map[num+1];
        // Remove range [num+1...new_end] in both maps.
        e_map.erase(new_end);
        s_map.erase(num+1);
      }
      if (e_map.count(num-1)) {
        new_start = e_map[num-1];
        s_map.erase(new_start);
        e_map.erase(num-1);
      }

      // insert {new_start, new_end} back to map
      s_map[new_start] = new_end;
      e_map[new_end] = new_start;
    }

    int best = 0;
    for (const auto& kv : s_map) {
      best = max(best, kv.second - kv.first + 1);
    }
    return best;
  }

};
int main() {
  Solution sol;
  vector<int> input = {100, 4, 200, 1, 3, 2};
  cout << sol.longestConsecutive(input) << endl;
}
