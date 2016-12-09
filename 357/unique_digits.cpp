class Solution {
public:
    void init() {
        dp.push_back(1);
        dp.push_back(9);
        int res = 9;
        int base = 9;
        for (int i=2;i<=10;++i) {
            res *= base;
            dp.push_back(res);
            base--;
        }
    }
    int f(int n) {
        if (n > 10) return 0;
        return dp[n];
   }

    vector<int> dp;
    int countNumbersWithUniqueDigits(int n) {
        init();
        int res = 0;
        for (int i=0;i<=n;++i) {
            res += f(i);
        }
        return res;
    }
};
