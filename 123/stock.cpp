#include <iostream>
#include <vector>
using namespace std;
// this can be done in O(kn)
class Solution {
public:
    int max(int a, int b) {
        return a > b ? a : b;
    }
    int maxProfit(vector<int>& prices) {
        int t = 2, n = prices.size();
        // dp[i][j] means the max profit achieved by i transactions, to prices j
        vector<vector<int>> dp(t+1, vector<int>(n, 0));
        // transition:
        // dp[i][j] = max(dp[i][j-1], dp[i-1][k] + (p[j]-p[k-1])) for best k
        for (int i=1;i<=t;++i) {
            int wtf;
            for (int j=0;j<n;++j) {
                if (j==0) {
                    wtf = -1 *prices[0];
                } else {
                    dp[i][j] = max(dp[i][j-1], prices[j] + wtf);
                    wtf = max(wtf, dp[i-1][j-1] - prices[j]);
                }
            }
        }
        return n > 0 ? dp[t][n-1] : 0;
    }
};

int main() {
    vector<int> input = {};
    Solution sol;
    cout << sol.maxProfit(input) << endl;
}
