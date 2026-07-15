class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n= nums.size();
        unordered_map<int,int> mp;
        vector<pair<int,int>> v;
        vector<int> ans;
        for(auto x: nums){
            mp[x]++;
        }


        for(auto [key,value]: mp){
           v.push_back(make_pair(key,value));
        }
        sort(v.begin(),v.end(),[](const auto& a,const auto &b){return a.second>b.second;});
        int i=0;
        while(k--){
            ans.push_back(v[i].first);
            i++;
        }
        return ans;
    }
};
