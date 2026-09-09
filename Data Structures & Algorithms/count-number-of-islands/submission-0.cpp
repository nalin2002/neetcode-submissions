class Solution {
public:
    int dx[4]={0,1,-1,0};
    int dy[4]={1,0,0,-1};
    bool isbound(int i,int j,int n,int m){
        if( i<0 || i>=n || j<0|| j>=m) return false;

        return true;
    }
    void dfs(vector<vector<char>>& grid, int x,int y,int n,int m,vector<vector<bool>>& visited){
        
        visited[x][y]=true;

        for(int i=0;i<4;i++){
            int n_x= x+dx[i];
            int n_y= y+dy[i];

            if( isbound(n_x,n_y,n,m) && grid[n_x][n_y]=='1' && !visited[n_x][n_y]){
                dfs(grid,n_x,n_y,n,m,visited);
            }
        }

    }
    int numIslands(vector<vector<char>>& grid) {
        int n= grid.size();
        int m= grid[0].size();

        vector<vector<bool>> visited(n,vector<bool>(m,false));
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid[i][j]=='1'){
                    dfs(grid,i,j,n,m,visited);
                    count++;
                }
            }
        }
        return count;
    }
};
