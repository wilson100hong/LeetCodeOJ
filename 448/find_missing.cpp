#include <vector>
#include <iostream>
using namespace std;


class Solution {
  public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
      int n = nums.size();
      int i = 0;
      while (i < n) {
        cout << "i: " << i << endl;
        if (nums[i] == i+1 || nums[nums[i]-1] == nums[i]) {
          i++;
          continue;
        }
        swap(nums[i], nums[nums[i]-1]);
      }
      vector<int> res;
      for (int i=0;i<n;++i) {
        if (nums[i] != i + 1) {
          res.push_back(i + 1);
        }
      }
      return res;
    }
};

int main() {
  Solution sol;
  vector<int> input = {4,3,2,7,8,2,3,1};
  auto ans = sol.findDisappearedNumbers(input);
  for (int a : ans) cout << a << endl;
}
