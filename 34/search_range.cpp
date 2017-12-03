class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res = {-1, -1};
        if (nums.size() == 0) return res;

        int l=0, r=nums.size()-1;
        // find begin
        while (l<r) {
            int m = (l+r)/2;
            if (nums[m] < target) {
                l = m+1;
            } else {
                r = m;
            }
            // !
            //} else if (nums[m] > target) {
                //r = m-1;
            //} else {
                //r = m;
            //}
        }

        if (nums[l] != target) return res;
        res[0] = l;

        // l=0;  // don't need to reset l!
        r=nums.size()-1;
        while (l<r) {
            int m = (l+r+1)/2;
            if (nums[m] > target) {
                r = m-1;
            } else {
                l = m;
            }

            //} else if (nums[m] < target) {
                //l = m+1;
            //} else {
                //l = m;
            //}
        }
        res[1] = l;

        return res;
    }
};
