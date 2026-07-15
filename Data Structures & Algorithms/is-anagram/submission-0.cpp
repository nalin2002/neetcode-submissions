class Solution {
public:
    bool isAnagram(string s, string t) {
        int n=s.size();
        int m= t.size();
        if(n!=m) return false;

        unordered_map<char,int> mp1,mp2;

        for(auto x: s){
            mp1[x]++;
        }
        for(auto x: t){
            mp2[x]++;
        }
        
        return mp1==mp2;
    }
};
