class Solution {
public:
    
    int paths(int x1,int y1,int x2,int y2,int m,int n,vector<vector<int>>& memo){
        if(x2==0 || y2==0) return 1;
        if(x1<0 || y1<0 || x2<0|| y2<0 ) return 0;
        if (memo[x2][y2] != -1) return memo[x2][y2];
       

        return memo[x2][y2]= paths(0,0,x2-1,y2,m,n,memo)+ paths(0,0,x2,y2-1,m,n,memo);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> memo(m, vector<int>(n, -1));
        return paths(0,0,m-1,n-1,m,n,memo);
    }
};
