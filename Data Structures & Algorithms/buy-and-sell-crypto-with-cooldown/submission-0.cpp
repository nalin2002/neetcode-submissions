class Solution {
public:
    int dfs(int i, bool buying, vector<int>& prices, vector<vector<int>>& dp) {
        if (i >= prices.size()) return 0;
        if (dp[i][buying] != -1) return dp[i][buying];

        if (buying) {
            int buy = dfs(i + 1, false, prices, dp) - prices[i];
            int cooldown = dfs(i + 1, true, prices, dp);
            return dp[i][buying] = max(buy, cooldown);
        } else {
            // Selling triggers a 1-day cooldown, so skip to i + 2
            int sell = dfs(i + 2, true, prices, dp) + prices[i];
            int cooldown = dfs(i + 1, false, prices, dp);
            return dp[i][buying] = max(sell, cooldown);
        }
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return dfs(0,true,prices,dp);
    }
};
