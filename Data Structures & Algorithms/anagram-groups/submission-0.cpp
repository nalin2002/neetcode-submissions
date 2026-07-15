class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n=strs.size();
        vector<vector<string>> ans;
        unordered_map<string,vector<string>> mp;
        for(auto x: strs){
            string s= x;
            sort(s.begin(),s.end());
            mp[s].push_back(x);
        }
        for(auto [key,val] : mp){
            ans.push_back(val);
        }
        return ans;

    }
};
