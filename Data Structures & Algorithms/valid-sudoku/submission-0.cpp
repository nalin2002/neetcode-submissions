class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n=9;
        vector<int> check(10,0);
        for(auto row: board){
            for(int i=0;i<9;i++){
                int val= row[i]-'0';
                if (val>=1 && val<=9 ){
                if(check[val]==0){
                    check[val]=1;
                }
                else{
                    return false;
                }
                }
            }
            fill(check.begin(),check.end(),0);
        }
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                int val = board[j][i]-'0';
                if (val>=1 && val<=9 ){
                if(check[val]==0){
                    check[val]=1;
                }
                else{
                    return false;
                }
                }
            }
            fill(check.begin(),check.end(),0);
        }
        fill(check.begin(),check.end(),0);
        int x=0,y=0;
        while(1){

            for(int i=x;i<x+3;i++){
                for(int j=y;j<y+3;j++){
                    int val = board[i][j]-'0';
                    if (val>=1 && val<=9 ){
                        if(check[val]==0){
                            check[val]=1;
                        }
                        else{
                            return false;
                        }
                    }
                }
            }
            fill(check.begin(),check.end(),0);
            y=y+3;

            if(y==9){
                x=x+3;
                y=0;
                fill(check.begin(),check.end(),0);
            }
            if(x==9){
                break;
            }
        }
        return true;
    }
};
