class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> output(nums.size(), 1);
        int p = 1;
        for (int i=0;i<nums.size();++i) {
            output[i]*= p;
            p *= nums[i];
        }
        p = 1;
        for (int i=nums.size()-1;i>=0;--i) {
            output[i]*= p;
            p *= nums[i];
        }
        return output;
    }
};
