#include <cstring>
class Solution {
public:
int memo[302][302];
    int solve(const std::vector<int>& padded, int l, int r){
        if(l>r) return 0;

        if (memo[l][r] != -1) return memo[l][r];

        int ans=0;

        for(int k=l;k<=r;k++){
            int coins= padded[l - 1] * padded[k] * padded[r + 1];
            coins += solve(padded, l, k - 1) + solve(padded, k + 1, r);
            ans = std::max(ans, coins);
        }

        return memo[l][r] = ans;
    }
    int maxCoins(vector<int>& nums) {
        int n= nums.size();

        vector<int> padded(n+2,1);
        for(int i=0;i<n;i++) padded[i+1]= nums[i];
        std::fill(&memo[0][0], &memo[0][0] + sizeof(memo) / sizeof(int), -1);
        return solve(padded,1,n);
    }
};
