class Solution {
public:
    int count(string s,int i,string t,int j){

       if(j<0) return 1;
       if(i<0) return 0;

       if(s[i]==t[j]){
        return count(s,i-1,t,j-1)+ count(s,i-1,t,j);
       }

       return count(s,i-1,t,j);

    }
    int numDistinct(string s, string t) {
        int n=s.size();
        int m= t.size();
        if(m>n) return 0;
        if(n==0||m==0) return 0;
        if(s==t) return 1;

        vector<vector<int>> dp(n+1,vector<int>(m+1,0));

        for(int i=0;i<=n;i++){
            dp[i][0]=1;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j]= dp[i-1][j]+dp[i-1][j-1];
                }
                else{
                    dp[i][j]= dp[i-1][j];
                }
            }
        }
        return dp[n][m];

//        return count(s,n-1,t,m-1);
    }
};
