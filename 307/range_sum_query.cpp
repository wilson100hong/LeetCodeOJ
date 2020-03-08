#include <vector>
#include <iostream>

using namespace std;

class NumArray {
public:
    NumArray(vector<int>& nums) {
        nums_.assign(nums.size(), 0);
        BIT_.assign(nums.size() + 1, 0);  // size+1
        for (int i=0;i<nums.size();++i) {
            update(i, nums[i]);
        }
    }
    
    void update(int i, int val) {
        int delta = val - nums_[i];
        int index = i + 1;
        while (index < BIT_.size()) {
            BIT_[index] += delta;
            index += (index & -index);
        }
        nums_[i] = val;
    }
    
    int sumRange(int i, int j) {
        return sumToI(j) - sumToI(i-1);
    }
    
    int sumToI(int i) {
        int sum = 0;
        int index = i + 1;
        while (index > 0) {
            sum += BIT_[index];
            index = index & index-1;
        }
        return sum;
    }
    
    vector<int> nums_;
    vector<int> BIT_;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */

int main() {
  vector<int> input = {1, 3, 5};
  NumArray* obj = new NumArray(input);
  cout << obj->sumRange(0,2) << endl;
  obj->update(1,2);
  cout << obj->sumRange(0,2) << endl;
}
