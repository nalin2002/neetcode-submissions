class Solution {
public:
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};
    bool isbound(int i,int j,int n,int m){
        if( i<0 || i>=n || j<0|| j>=m) return false;

        return true;
    }
    void dfs(vector<vector<char>>& board, int x,int y,int n,int m,vector<vector<bool>>& visited){
        visited[x][y]= 'X';

        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny= y+ dy[i];

            if( isbound(nx,ny,n,m) && !visited[nx][ny] && board[nx][ny]=='O'){
                dfs(board,nx,ny,n,m,visited);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n= board.size();
        int m= board[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));

        for(int i=0;i<n;i++){
            if(board[i][0]=='O'){
                dfs(board,i,0,n,m,visited);
            }
            if(board[i][m-1]=='O'){
                dfs(board,i,m-1,n,m,visited);
            }
        }
        for(int i=0;i<m;i++){
            if(board[0][i]=='O'){
                dfs(board,0,i,n,m,visited);
            }
            if(board[n-1][i]=='O'){
                dfs(board,n-1,i,n,m,visited);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O' && !visited[i][j]){
                    board[i][j]='X';
                }
            }
        }
            
    }
};
