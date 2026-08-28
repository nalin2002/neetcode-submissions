class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n= matrix.size();
        int m= matrix[0].size();

        // reverse(matrix.begin(),matrix.end());

        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         swap(matrix[i][j], matrix[j][i]);
        //     }
        // }

        int l =0,r=n-1;

        while(l<r){
            for(int i=0;i<r-l;i++){
                int top= l;
                int bottom = r;

                int topleft = matrix[top][l+i];

                matrix[top][l+i] = matrix[bottom-i][l];
                matrix[bottom-i][l]= matrix[bottom][r-i];
                matrix[bottom][r-i]= matrix[top+i][r];
                matrix[top+i][r]= topleft;

            }
            l++;
            r--;
        }
    }
};
