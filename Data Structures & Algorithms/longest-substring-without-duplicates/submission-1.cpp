class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        if(n<=1) return n;
        unordered_set<char> dp;
        int l=0,r=0;
        int curr_size=0,max_size=0;
        while(r<n){
            while(dp.contains(s[r])){
                dp.erase(s[l]);
                l++;
            }
            dp.insert(s[r]);
            max_size= max(max_size,r-l+1);
            r++;
        }
        return max_size;
    }
};
