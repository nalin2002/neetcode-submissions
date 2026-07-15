class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n= nums.size();
        int prod=1;
        vector<int> left_prod(n),right_prod(n);
        for(int i=0;i<n;i++){
            if(i==0){
                left_prod[i]=1;
                right_prod[i+n-1]=1;
                continue;
            }
            if(i==1){
                left_prod[i]=nums[0];
                right_prod[n-2]=nums[n-1];
            }
            else{
                left_prod[i]= left_prod[i-1]*nums[i-1];
                right_prod[n-i-1]= right_prod[n-i]*nums[n-i];
            }
        }

        for(int i=0;i<n;i++){
            nums[i]= left_prod[i]*right_prod[i];
        }
        return nums;
    }
};
