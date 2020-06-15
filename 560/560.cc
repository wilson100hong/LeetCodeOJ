class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> accum(nums.size(), 0);
        unordered_map<int, int> cnt;
        cnt[0] = 1;  // Empty
        int ans = 0;
        for (int i=0;i<nums.size();++i) {
            accum[i] = (i > 0 ? accum[i-1] : 0) + nums[i];
            
            int j = accum[i] - k;
            if (cnt.count(j)) {
                ans += cnt[j];
            }
            cnt[accum[i]]++;
        }
        return ans;   
    }
};
