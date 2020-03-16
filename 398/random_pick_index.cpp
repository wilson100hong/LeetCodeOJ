#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    Solution(vector<int>& nums) {
        nums_ = nums;
    }
    
    int pick(int target) {
        int n = 0;
        int index = -1;
        for (int i=0;i<nums_.size();++i) {
            if (target != nums_[i]) continue;
            if (rand() % (++n) == 0) index = i;
        }
        return index;
    }
    
    vector<int> nums_;
};

