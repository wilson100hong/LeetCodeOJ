// find median

#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    // k-th is 0-based
    int findkth(vector<int>& nums, int L, int R, int kth) {
        // inplace partiton
        int pivot = nums[R];
        int i = L, j=R-1, k=0;
        while (i<=j) {
            if (nums[i] <= pivot) {
                i++;
            } else {
                // swap
                int temp = nums[j];
                nums[j] = nums[i];
                nums[i]= temp;
                j--;
                k++;
            }
        }
        int len = R-L-k;
        if (len == kth) {
            return pivot;
        } else if (len > kth) {
            return findkth(nums, L, R-k-1, kth);
        } else {
            return findkth(nums, R-k, R-1, kth-len-1);
        }
    }

    int abs(int x) {
        return x > 0 ? x : -x;
    }

    int minMoves2(vector<int>& nums) {
        int med = findkth(nums, 0, nums.size()-1, nums.size()/2);
        int ans = 0;
        for (int num : nums) {
            ans += abs(med-num);
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 1};
    cout << sol.findkth(nums, 0, nums.size()-1, nums.size()/2) << endl;
}
