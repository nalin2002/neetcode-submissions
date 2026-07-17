class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n= heights.size();
        int i=0,j=n-1;
        int ans=0;
        while(i<j){
            int curr_area= (j-i)*min(heights[i],heights[j]);
            if(curr_area>ans) ans=curr_area;

            if(heights[i]<heights[j]){
                i++;
            }
            else if(heights[i]>heights[j]){
                j--;
            }
            else{
                i++;
            }
        }

        return ans;
    }
};
