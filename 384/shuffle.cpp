// O(n): Fisher-Yates (Knuth algorithm P)
// https://en.wikipedia.org/wiki/Fisher%E2%80%93Yates_shuffle
//
class Solution {
public:
    Solution(vector<int> nums) {
        nums_ = nums;
        
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return nums_;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        int n = nums_.size();
        vector<int> res(n, 0);
        for (int i=0;i<n;++i) {
            int r = rand() % (i+1); // 0 ~ i
            if (r != i) {
                res[i] = res[r];
            }
            res[r] = nums_[i];
        }
        return res;
    }
    vector<int> nums_;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */
