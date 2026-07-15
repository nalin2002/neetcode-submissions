class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        unordered_set<int> hash(nums.begin(),nums.end());
        int ans=0;
        for(auto x: hash){
            if( hash.find(x-1) == hash.end() ){
                int l=1;
                while( hash.find(x+l) != hash.end() ){
                    l++;
                }
                ans=max(ans,l);
            }
        }
        return ans;
    }
};
