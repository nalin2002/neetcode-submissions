class Solution {
public:
    void backtrack(int start,vector<int>& curr, vector<vector<int>>& ans, vector<int>& nums){
        if(start==nums.size()){
            ans.push_back(curr);
            return;
        }
        curr.push_back(nums[start]);
        backtrack(start+1,curr,ans,nums);
        curr.pop_back();
        backtrack(start+1,curr,ans,nums);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n= nums.size();
        vector<vector<int>> ans;
        vector<int> curr;
        backtrack(0,curr, ans, nums);
        return ans;
    }
};
