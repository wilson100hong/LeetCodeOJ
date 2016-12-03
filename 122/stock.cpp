// O(n) solution!
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        bool bought = false;
        int buy_price = 0;
        int profit = 0;
        for (int i=0;i<prices.size();++i) {
            if (bought) {
                // rising stop, sell
                if (i==prices.size()-1 || prices[i+1] < prices[i]) {
                    profit += (prices[i] - buy_price);
                    bought = false;
                }
            } else {
                // falling stop, buy 
                if (i<prices.size()-1 && prices[i] < prices[i+1]) {
                    bought = true;
                    buy_price = prices[i];
                }
            }
        }
        return profit;
    }
};
