class Solution {
public:
    int partition(vector<int>& nums, int l, int r, int k) {
        // let nums[r] be pivot
        int index = l;
        for (int i=l;i<r;++i) {
            if (nums[i] > nums[r]) {
                swap(nums[index], nums[i]);
                index++;
            } 
        }

        swap(nums[r], nums[index]);
        return index;
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int pivot = partition(nums, l, r, k);
            if (pivot == k - 1) return nums[pivot];
            else if (pivot > k - 1) {
                r = pivot - 1;
            } else {
                l = pivot + 1; 
            }
        }
        return -1; // should not happen
    }
};
