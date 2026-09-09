class Solution {
public:
    bool isbound(int i,int j,int n,int m){
        if( i<0 || i>=n || j<0|| j>=m) return false;

        return true;
    }
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n= grid.size();
        int m= grid[0].size();

        int dx[4]={0,1,-1,0};
        int dy[4]={1,0,0,-1};

        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        queue< pair<pair<int,int>,int> > q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    q.push({{i,j},0});
                    dist[i][j]=0;
                }
            }
        }

        while(!q.empty()){
            int x= q.front().first.first;
            int y= q.front().first.second;
            int count= q.front().second;
            q.pop();

            for(int i=0;i<4;i++){
                int n_x= x+dx[i];
                int n_y= y+dy[i];

                if( isbound(n_x,n_y,n,m) && grid[n_x][n_y]==INT_MAX  ){
                    if(count+1<dist[n_x][n_y]){
                        dist[n_x][n_y]= count+1;
                        q.push({{n_x,n_y},count+1});
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==INT_MAX){
                    grid[i][j]=dist[i][j];
                }
            }
        }
    }
};
