class Solution {
public:
    void backtrack(int start,vector<int>& curr, vector<vector<int>>& ans, vector<int>& nums){
        if(start==nums.size()){
            ans.push_back(curr);
            return;
        }
        curr.push_back(nums[start]);
        backtrack(start+1, curr,ans,nums);

        curr.pop_back();
        while (start + 1 < nums.size() && nums[start] == nums[start + 1]) {
            start++;
        }
        backtrack(start+1, curr,ans,nums);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n= nums.size();
        vector<int> curr;
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        backtrack(0,curr, ans, nums);
        return ans;
    }
};
