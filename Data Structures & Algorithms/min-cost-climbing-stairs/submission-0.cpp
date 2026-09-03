class Solution {
public:
    vector<int> dp;
    int total_cost(vector<int>& cost,int index){
        if(index >= cost.size()){
            return 0;
        }
        if(dp[index]!=-1){
            return dp[index];
        }

        int cost1= cost[index] +  min( total_cost(cost,index+1) , total_cost(cost,index+2) );
            dp[index]= cost1;
        return cost1;
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n= cost.size();
        dp.resize(n+1,-1);
        return min( total_cost(cost,0) ,total_cost(cost,1) ); 
    }
};
