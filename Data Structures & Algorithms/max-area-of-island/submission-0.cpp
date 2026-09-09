class Solution {
public:
    int dx[4]={0,1,-1,0};
    int dy[4]={1,0,0,-1};
    bool isbound(int i,int j,int n,int m){
        if( i<0 || i>=n || j<0|| j>=m) return false;

        return true;
    }
    void dfs(vector<vector<int>>& grid, int x,int y,int n,int m,vector<vector<bool>>& visited,int& area){
        
        visited[x][y]=true;
        area++;

        for(int i=0;i<4;i++){
            int n_x= x+dx[i];
            int n_y= y+dy[i];

            if( isbound(n_x,n_y,n,m) && grid[n_x][n_y]==1 && !visited[n_x][n_y]){
                dfs(grid,n_x,n_y,n,m,visited,area);
            }
        }

    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n= grid.size();
        int m= grid[0].size();

        vector<vector<bool>> visited(n,vector<bool>(m,false));
        int max_area=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid[i][j]==1){
                    int area=0;
                    dfs(grid,i,j,n,m,visited,area);
                   max_area= max(max_area,area);
                }
            }
        }
        return max_area;
    }
};
