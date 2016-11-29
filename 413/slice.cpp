// this could be done in O(n)
#include <iostream>
#include <vector>
using namespace std;

int max(int a, int b) {
    return a > b ? a : b;
}
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size();
        int ans = 0;

        int s = 0;
        int diff;
        // t > s
        for (int t=1;t<n;++t) {
            if (t-s == 1) {
                diff = A[t]-A[s];
            } else if (A[t]-A[t-1] == diff) {
                ans += (t-s-1);
            } else {   // diff change
                s = t-1;
                diff = A[t]-A[s];
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> input = {1, 2, 3, 4, 5, 6};
    cout << sol.numberOfArithmeticSlices(input) << endl;
}
