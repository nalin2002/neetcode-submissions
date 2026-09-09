class Solution {
public:
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};
    bool isbound(int i,int j,int n,int m){
        if( i<0 || i>=n || j<0|| j>=m) return false;

        return true;
    }
    void dfs(vector<vector<int>>& heights, int x,int y,int n,int m,vector<vector<bool>>& visited){
        visited[x][y]= true;

        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny= y+ dy[i];

            if( isbound(nx,ny,n,m) && !visited[nx][ny] && heights[nx][ny]>=heights[x][y]){
                dfs(heights,nx,ny,n,m,visited);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n= heights.size();
        int m= heights[0].size();

        vector<vector<bool>> pacific(n,vector<bool>(m,false));
        vector<vector<bool>> atlantic(n,vector<bool>(m,false));

        for(int i=0;i<m;i++){
            if(!pacific[0][i]){
                dfs(heights,0,i,n,m,pacific);
            }
            if(!atlantic[n-1][i]){
                dfs(heights,n-1,i,n,m,atlantic);
            }
        }
        for(int i=0;i<n;i++){
            if(!pacific[i][0]){
                dfs(heights,i,0,n,m,pacific);
            }
            if(!atlantic[i][m-1]){
                dfs(heights,i,m-1,n,m,atlantic);
            }
        }
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pacific[i][j] && atlantic[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
        
    }
};
