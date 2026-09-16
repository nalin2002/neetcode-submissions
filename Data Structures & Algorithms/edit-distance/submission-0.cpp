class Solution {
public:

    int count(string& word1, int i,string& word2,int j){

        if(j<0) return i+1;
        if(i<0) return j+1;

        if(word1[i]==word2[j]){
            return count(word1,i-1,word2,j-1);
        }

        int cnt1= 1+count(word1,i-1,word2,j);
        int cnt2= 1+count(word1,i,word2,j-1);
        int cnt3= 1+ count(word1,i-1,word2,j-1);

        return min(cnt1,min(cnt2,cnt3));
    }
    int minDistance(string word1, string word2) {
        int m=word1.size();
        int n= word2.size();

       // return count(word1,n-1,word2,m-1);

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 0; i <= m; ++i) dp[i][0] = i;
        for (int j = 0; j <= n; ++j) dp[0][j] = j;

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    int insertOp  = dp[i][j - 1];
                    int deleteOp  = dp[i - 1][j];
                    int replaceOp = dp[i - 1][j - 1];
                    
                    dp[i][j] = 1 + min({insertOp, deleteOp, replaceOp});
                }
            }
        }

        return dp[m][n];
    }
};
