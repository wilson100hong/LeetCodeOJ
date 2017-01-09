#include <iostream>
using namespace std;
// range based binary search
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        k--;  // 0 based
        int n = matrix.size();
        int lo = matrix[0][0], hl = matrix[n-1][n-1];
        while (lo < hl) {
            int mi = (lo + hl) / 2;
            // find how many elements smaller than mi
            int c = n-1;
            int smaller_equal = 0;
            for (int r=0;r<n;++r) {
                while (matrix[r][c] > mi && c >= 0) {
                    c--;
                }
                smaller_equal += (c+1);
            }

            // trick!
            if (smaller_equal <= k) {
                lo = mi+1;
            } else {  // mi is still possible
                hl = mi;
            }
        }
        return hl;
    }
};

int main() {
    vector<vector<int>> input = {{1,5,9},{10,11,13},{12,13,15}};
    Solution sol;
    cout << sol.kthSmallest(input, 8);
}
