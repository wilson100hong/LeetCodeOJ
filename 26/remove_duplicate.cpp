class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n==0) return 0;
        int j = 1;
        int last = nums[0];
        for (int i=1;i<n;++i) {
            if (nums[i] != last) {
                nums[j++] = nums[i];
            }
            last = nums[i];
        }
        return j;
    }
};
