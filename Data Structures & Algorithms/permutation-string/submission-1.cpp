class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        if(s1==s2) return true;
        if(n>m) return false;
        int l=0,r=n-1;
        std::array<int,26> count_s1={0};
        for(auto& x: s1){
            count_s1[x-'a']++;
        }
        std::array<int,26> count_s2={0};
        for(int i=l;i<=r;i++){
            count_s2[s2[i]-'a']++;
        }
       
        while(r<m){
             if(count_s1==count_s2) return true;

             r++;
             if(r==m) break;
             count_s2[s2[r]-'a']++;
             count_s2[s2[l]-'a']--;
             l++;
        }
        return false;
    }
};
