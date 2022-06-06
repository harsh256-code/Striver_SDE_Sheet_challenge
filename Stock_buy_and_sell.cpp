class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = INT_MIN,lowest=INT_MAX;
        for(int i =0;i<prices.size();i++){
            lowest = min(lowest,prices[i]);
            profit = max(profit,prices[i]-lowest);
        }
        return profit;
    }
};
