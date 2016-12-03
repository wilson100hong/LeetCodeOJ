class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min;
        int profit = 0;
        for (int i=0;i<prices.size();i++) {
            if (i == 0) {
                min = prices[i];
                continue;
            }
            int gain = prices[i] - min;
            if (gain > profit) {
                profit = gain;
            }
            if (prices[i] < min) {
                min = prices[i];
            }
        }
        return profit;
    }
};
