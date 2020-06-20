class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> output(nums.size(), 1);
        for (int i=1;i<nums.size();++i) {
            output[i] = output[i-1] * nums[i-1];
        }
        int cur = 1;
        for (int i=nums.size()-2;i>=0;--i) {
            cur *= nums[i+1];
            output[i] *= cur;
        }
        return output;
    }
};
