class Solution {
public:
    int func(string text1,int i,string text2,int j,vector<vector<int>>& dp,int n,int m){
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans1=0,ans2=0;
        if(text1[i]==text2[j]){
            ans1= 1+ func(text1,i-1,text2,j-1,dp,n,m);
        }
        ans2= max( func(text1,i-1,text2,j,dp,n,m) ,func(text1,i,text2,j-1,dp,n,m) );

        return dp[i][j]=max(ans1,ans2);
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n= text1.size();
        int m= text2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return func(text1,n-1,text2,m-1,dp,n,m);
    }
};
