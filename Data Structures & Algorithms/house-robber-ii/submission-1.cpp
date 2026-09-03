class Solution {
public:
    
    int max_money(vector<int>& nums,int index,int end, vector<int>& memo ){
        if(index>end) return 0;

        if(memo[index]!=-1) return memo[index];
        
        int m1= nums[index]+ max_money(nums,index+2,end,memo);
        int m2= max_money(nums,index+1,end,memo);

        return memo[index]=max(m1,m2);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int> memo1(n,-1);
        int case1= max_money(nums,0,n-2,memo1);
        vector<int> memo2(n,-1);
        int case2= max_money(nums,1,n-1,memo2);

        return max(case1,case2);
    }
};
