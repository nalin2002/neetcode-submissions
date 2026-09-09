class Solution {
public:
     bool isbound(int i,int j,int n,int m){
        if( i<0 || i>=n || j<0|| j>=m) return false;

        return true;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n= grid.size();
        int m=grid[0].size();
        int max_time =0;

        int dx[4]={0,1,-1,0};
        int dy[4]={1,0,0,-1};

        vector<vector<int>> dist(n,vector<int>(m,-1));
        queue< pair<pair<int,int>,int> > q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
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

                if( isbound(n_x,n_y,n,m) && grid[n_x][n_y]==1  ){
                    if(dist[n_x][n_y]==-1){
                        dist[n_x][n_y]= count+1;
                        q.push({{n_x,n_y},count+1});
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    if( dist[i][j]==-1) return -1;
                    max_time= max(max_time,dist[i][j]);
                }
            }
        }

        return max_time;

    }
};
