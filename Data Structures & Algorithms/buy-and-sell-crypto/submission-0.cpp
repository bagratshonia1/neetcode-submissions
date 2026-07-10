class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minLeft = INT_MAX;
        int result = 0;
        for(int i = 0; i < prices.size(); i++){
            minLeft = min(prices[i], minLeft);
            int currProfit = prices[i] - minLeft;
            result = max(result, currProfit);
        }
        return result;
    }
};
