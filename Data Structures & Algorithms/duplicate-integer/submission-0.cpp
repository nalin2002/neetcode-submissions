class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int n= nums.size();
        unordered_set<int> hash;
        for(auto x: nums){
            if( hash.find(x)!=hash.end() ) return true;

            hash.insert(x);
            
        }
        return false;
    }
};