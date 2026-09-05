class Solution {
public:
    vector<int> memo;
    int dfs(int i,string& s){
        if(i==s.size()) return 1;
        if(s[i]=='0') return 0;

        if(memo[i]!=-1) return memo[i];

        int res= dfs(i+1,s);

        if(i+1<s.size() && (s[i]=='1' || (s[i]=='2' && s[i+1<='6']))){
            res+= dfs(i+2,s);
        }

        return memo[i]=res;
    }
    int numDecodings(string s) {
        int n=s.size();
       // memo.resize(n,-1);

       vector<int> dp(n+1,0);
       dp[n]=1;
       for(int i=n-1;i>=0;i--){
        if(s[i]=='0'){
            dp[i]=0;
        }
        else{
            dp[i]= dp[i+1];
            if(i+1<n && (s[i]=='1' || (s[i]=='2' && s[i+1]<= '6'))){
                dp[i]+=dp[i+2];
            }
        }
       }
       return dp[0];
      //  return dfs(0,s);
    }
};
