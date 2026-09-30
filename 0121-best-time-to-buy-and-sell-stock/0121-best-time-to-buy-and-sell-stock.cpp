class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minium = INT_MAX;
        int maxprofit = 0;

        for (int i = 0; i < prices.size(); i++) {
            minium = min(minium, prices[i]);
            maxprofit = max(maxprofit, prices[i] - minium);
        }
        return maxprofit;
    }
};