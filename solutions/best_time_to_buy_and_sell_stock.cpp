class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) return 0;

        int minPrice = prices[0]; 
        int maxProfit = 0; 

        for (int j = 1; j < prices.size(); j++) {
            int profit = prices[j] - minPrice; 
            if (profit > maxProfit) {
                maxProfit = profit;
            }
            if (prices[j] < minPrice) {
                minPrice = prices[j]; 
            }
        }

        return maxProfit;
    }
};