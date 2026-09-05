class Solution {
public:
    vector<int> memo;
    int count(vector<int>& coins, int amt){
        int n=coins.size();
        if(amt==0) return 0;
        if(amt<0) return 1e9;

        if(memo[amt]!=-1) return memo[amt];

        int mincoins= 1e9;
        for(int& coin: coins){
            mincoins= min(mincoins,1+count(coins,amt-coin));
        }
        return memo[amt]= mincoins;
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        // memo.resize(amount+1,-1);
        // int ans= count(coins,amount);
        // return ans>=1e9? -1: ans;
        vector<int> dp(amount+1, amount+1);
        dp[0]=0;
        for(int i=1;i<=amount;i++){
            for(auto& coin: coins){
                if(i-coin>=0){
                    dp[i]= min(dp[i], 1+ dp[i-coin]);
                }
            }
        }
        return dp[amount]> amount?-1:dp[amount];
    }
};
