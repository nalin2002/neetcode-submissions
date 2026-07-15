class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> s;
        int n= nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i=0;i<n-2;i++){
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int j=i+1,k=n-1;
            int req_sum = -nums[i];
            while(j<k){
                int sum= nums[j]+nums[k];
                
                if(sum<req_sum){
                    j++;
                }
                else if(sum>req_sum){
                    k--;
                }
                else{
                   // s.insert({nums[i],nums[j],nums[k]});
                   ans.push_back({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                     while(j<k && nums[j]==nums[j-1]){
                    j++;
                }
                while(j<k  && nums[k]==nums[k+1]){
                    k--;
                }
                   
                }
            }
        }


        return ans;
    }
};
