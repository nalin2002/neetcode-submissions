class Solution {
public:
    vector<int> dp;
    int max_money(vector<int>& nums,int index){
        if(index >= nums.size()){
            return 0;
        }
        if(dp[index]!=-1) return dp[index];
        
        int m1= nums[index]+ max_money(nums,index+2);

        int m2= max_money(nums,index+1);

        return dp[index]=max(m1,m2);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        dp.resize(n+1,-1);
        //return max_money(nums,0);
        int rob1=0,rob2=0;

        for(int& m: nums){
            int temp= max(m+rob1,rob2);
            rob1=rob2;
            rob2=temp;
        }
        return rob2;
    }
};
