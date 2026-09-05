class Solution {
public: 
    vector<vector<bool>> dp;
    bool ispalindrome(string& s, int i,int j){
        if(i>=j) return true;
        if(s[i]!=s[j]) return false;
        return ispalindrome(s,i+1,j-1);
    }
    string isreq(string& s, int i, int j){
        if(i>j) return "";
       // if(dp[i][j]!="#") return dp[i][j];

        if( ispalindrome(s,i,j) ){
            return s.substr(i,j-i+1);
        }

        string left= isreq(s,i+1,j);
        string right = isreq(s,i,j-1);

        return left.size()>right.size()?left:right;
    }
    string longestPalindrome(string s) {
        int n= s.size();
        if(n<=1) return s;
        dp.resize(n,vector<bool>(n));
       // return isreq(s,0,n-1);
       for(int i=0;i<n;i++){
        dp[i][i]= true;
       }
       int start=0,maxlen=1;

        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                if(s[i]==s[j]){
                    if(j-i<=2 || dp[i+1][j-1]){
                        dp[i][j]= true;

                        if(j-i+1>maxlen){
                            start=i,maxlen= j-i+1;
                        }
                    }
                }
            }
        }

        return s.substr(start,maxlen);
    }
};
