class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> pnums;
        for (int i=0;i<nums.size();++i) {
            pnums.push_back(make_pair(nums[i], i));
        }
        
        
        sort(pnums.begin(), pnums.end());
        
        int i=0, j=pnums.size()-1;
        while (i<j) {
            int sum = pnums[i].first + pnums[j].first;
            if (sum == target) {
                return {pnums[i].second, pnums[j].second};
            } else if (sum > target) {
                j--;
            } else {
                i++;
            }
        }
        return {0, 0};  // should not happen
    }
};
