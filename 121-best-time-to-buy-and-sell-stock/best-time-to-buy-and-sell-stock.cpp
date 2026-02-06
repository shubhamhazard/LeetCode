class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minBuy = prices[0];
        int profit = 0, maxProfit = 0;

        for(int i=1; i<prices.size(); i++)
        {
            if(prices[i] > minBuy)
            {
                profit = max(profit, prices[i]-minBuy);
            }
            minBuy = min(minBuy, prices[i]);
        }
        return profit;
    }
};