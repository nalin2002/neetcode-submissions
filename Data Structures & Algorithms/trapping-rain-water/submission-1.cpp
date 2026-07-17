class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        if(n<=2) return 0;

        int ans=0;

        vector<int> left_max(n,0),right_max(n,0);
        left_max[0]=height[0],right_max[n-1]=height[n-1];
        for(int i=1;i<n;i++){
            left_max[i]= max(left_max[i-1],height[i]);
            right_max[n-1-i]= max(right_max[n-i],height[n-1-i]);
        }
        for(int i=0;i<n;i++){
            ans+= (min(left_max[i],right_max[i])-height[i]);
        }

        int res=0;
        int i=0,j=n-1;
        int lmax= height[i],rmax= height[j];
        while(i<j){
            if(lmax<rmax){
                i++;
                lmax= max(lmax,height[i]);
                res+= lmax-height[i];
            }
            else{
                j--;
                rmax=max(rmax,height[j]);
                res+= rmax-height[j];
            }
        }

        return res;
    }
};
