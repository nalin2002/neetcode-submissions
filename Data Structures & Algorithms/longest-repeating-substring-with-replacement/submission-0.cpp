class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        std::array<int,26> count={0};

        int l=0,maxlen=0,maxcount=0;
        for(int r=0;r<n;r++){
            count[s[r]-'A']++;
            maxcount= max(maxcount, count[s[r]-'A']);

            while( (r-l+1)-maxcount>k){
                count[s[l]-'A']--;
                l++;
            }
            maxlen= max(maxlen,r-l+1);
        }
        return maxlen;
    }
};
