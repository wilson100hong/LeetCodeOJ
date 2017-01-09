// there is O(1) solution!
class Solution {
public:
    // O(n):
    // http://keithschwarz.com/interesting/code/?dir=find-duplicate<Paste>
    int findDuplicate(vector<int>& nums) {
		int s = nums.size()-1;
        int i = s, j = s;
        // A[i] should be i+1
        while (1) {
            i = nums[i] - 1;
            j = nums[j] - 1; j = nums[j] - 1;
            if (i == j) {
                break;
            }
        }

        i = s;
        while (i != j) {
            i = nums[i] - 1;
            j = nums[j] - 1;
        }
        for (int m=0;m<nums.size();++m) {
            if (nums[m]-1 == i) {
                return nums[m];
            }
        }
        return -1;
    }

    // O(nlogn)
    /*
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int lo = 1, hl = n;
        while (lo < hl) {
            int mi = lo + (hl-lo)/2;
            // cnt number <= mi
            int se = 0;
            for (int x : nums) {
                if (x <= mi) {
                    se++;
                }
            }

            if (se <= mi) {
                lo = mi + 1;
            } else {
                hl = mi;
            }
        }
        return hl;
    }
    */
};
