#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

class Solution {
public:

  vector<int> countSmaller(vector<int>& nums) {
    set<int> uniq_nums;
    
    for (int n : nums) {
      uniq_nums.insert(n);
    }

    map<int, int> num_to_bit_index;
    int index = 1;
    for (int n : uniq_nums) {
      num_to_bit_index[n] = index++;
    }

    // Init
    bit_.assign(uniq_nums.size() + 1, 0);

    vector<int> res(nums.size(), 0);
    for (int i = nums.size() - 1; i >= 0; --i) {
      int n = nums[i];
      // Get number of elements <= n
      int index = num_to_bit_index[n];
      int cnt = 0;
      int index2 = index - 1;
      while (index2 > 0) {
        //cout << "index2: " << index2 << endl;
        cnt += bit_[index2];
        index2 &= (index2 - 1);
      }
      res[i] = cnt;

      // add count of index
      while (index < bit_.size()) {
        bit_[index]++;
        index += (index & -index);
      }
    }
    return res;
  }


  // For BIT
  vector<int> bit_;
};

int main() {
  vector<int> input = {5,2,6,1};
  Solution sol;
  auto ans = sol.countSmaller(input);
  for (int a : ans) {
    cout << a << endl;
  }
}
