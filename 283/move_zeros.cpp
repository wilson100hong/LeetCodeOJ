#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i=0,j=0;
        int n = nums.size();
        while (i<n) {
            if (nums[i] != 0) {
                swap(nums[i], nums[j]);
                j++;
            }
            i++;
        }
    }
};

int main() {
    vector<int> input = {0, 1, 0, 3, 12};
    Solution sol;
    sol.moveZeroes(input);
    for (int x : input) {
        cout << x << endl;
    }
}
