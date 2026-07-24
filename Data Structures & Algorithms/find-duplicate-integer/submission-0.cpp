class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n= nums.size();
        vector<int> count(n,0);
        for(auto x: nums){
            if(count[x]==0)
             count[x]++;
            else{
                return x;
            }
            
        }
        return 0;
    }
};
