class Solution {

public:

    void backtrack(int start, int target, vector<int>& curr, vector<vector<int>>& ans, vector<int>& nums){
        if(target==0){
            ans.push_back(curr);
            return;
        }
        if(target<0 || start==nums.size()){
            return;
        }

        curr.push_back(nums[start]);
        backtrack(start,target-nums[start],curr, ans,nums);
        //backtrack(start+1,target-nums[start],curr,ans,nums);

        curr.pop_back();
        backtrack(start+1,target, curr, ans, nums);

    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        int n=nums.size();

        vector<vector<int>> ans;
        vector<int> curr;
        backtrack(0,target,curr,ans,nums);
        return ans;
    }
};
