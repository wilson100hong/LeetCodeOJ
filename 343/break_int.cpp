// This needs observation: separate by 3 is optimal until 4
// 3(a-3) > a when a > 4.5
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        if (n==2) return 1;
        if (n==3) return 2;
        if (n==4) return 4;
        int res = 1;
        while (n > 4) {
            n -= 3;
            res *= 3;
        }
        return res *= n;
    }

    // slow solution: dp
    /*
    vector<int> dp;
    int max(int a, int b) {
        return a > b ? a : b;
    }
    void init() {
        dp.push_back(0);
        dp.push_back(1);
        for (int i=2;i<=58;++i) {
            int best = i;
            for (int a=1;a<=(i/2);++a) {
                int b = i - a;
                if (dp[a] * dp[b] > best) {
                    best = dp[a] * dp[b];
                }
            }
            dp.push_back(best);
        }
    }
    int integerBreak(int n) {
        init();
        int best = 0;
        for (int a=1;a<=(n/2);++a) {
            int b = n - a;
            if (dp[a] * dp[b] > best) {
                best = dp[a] * dp[b];
            }
        }
        return best;
    }
    */
};

int main() {
    Solution sol;
    cout << sol.integerBreak(6) << endl;
    cout << sol.integerBreak(7) << endl;
    cout << sol.integerBreak(8) << endl;
    cout << sol.integerBreak(9) << endl;
    cout << sol.integerBreak(10) << endl;
    cout << sol.integerBreak(11) << endl;
    cout << sol.integerBreak(12) << endl;
    cout << sol.integerBreak(13) << endl;
}
