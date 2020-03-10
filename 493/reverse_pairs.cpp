#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

class Solution {
public:
  int reversePairs(vector<int>& nums) {
    if (nums.empty()) return 0;
  
    set<int> uniq_nums;
    for (int num : nums) {
      uniq_nums.insert(num);
    }

    vector<int> bit(uniq_nums.size()+1, 0);

    // num to bit index
    map<int, int> num_to_bi;
    int bi = 1;
    for (int un : uniq_nums) {
      //cout << "num: " << un << ", bi: " << bi << endl;
      num_to_bi[un] = bi++;
    }

    update(bit, num_to_bi[nums[nums.size()-1]], 1); 
    
    int cnt = 0;
    for (int i=nums.size()-2;i>=0;--i) {
      if (nums[i] == 0) {
        auto iter = uniq_nums.lower_bound(0);
        if (iter != uniq_nums.begin()) {
          iter--;
          cnt += query(bit, num_to_bi[*iter]);
        }
      } else {
        int target;
        if (nums[i] > 0) {
          target = (nums[i]-1)/2;
        } else {
          target = nums[i]/2-1;
        }
        auto iter = uniq_nums.upper_bound(target);
        if (iter != uniq_nums.begin()) {
          iter--;
          cnt += query(bit, num_to_bi[*iter]);
        }
      }
      update(bit, num_to_bi[nums[i]], 1); 
    }
    return cnt;
  }

  int query(const vector<int>& bit, int index) {
    int sum = 0;
    while (index > 0) {
      sum += bit[index];
      index -= (index & -index);
    }
    return sum;
  }

  void update(vector<int>& bit, int index, int delta) {
    while (index < bit.size()) {
      bit[index] += delta;
      index += (index & -index);
    }
  }
};


int main() {
  Solution sol;
  vector<int> input;
  //input = {1,3,2,3,1};
  //cout << sol.reversePairs(input) << endl;
  //input = {2,4,3,5,1};
  //cout << sol.reversePairs(input) << endl;
  input = {1,0,3,24,25,0,11,7,19,0,5,16,17,4,19,20,20,0,14};
  cout << sol.reversePairs(input) << endl;

}
