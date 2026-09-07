class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        int ans=0,maxprofit=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int diff= prices[j]-prices[i];
                ans= max(ans,diff);
            }
        }
        int l=0,r=1;
        while(r<n){
            if(prices[l]<prices[r]){
                int profit= prices[r]-prices[l];
                maxprofit= max(maxprofit,profit);
            }
            else{
                l=r;
            }
            r++;
        }
        return maxprofit;
    }
};
