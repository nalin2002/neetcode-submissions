class Solution {
public:
    int match(string& s,int i,string& p,int j){
        if(j<0 ) return i<0;
        if(i<0) {
            if(p[j]=='*') 
            return match(s,i,p,j-2);
            
            return false;
        }

        if(s[i]==p[j] || p[j]=='.') return match(s,i-1,p,j-1);

        if(p[j]=='*'){
            bool ignore= match(s,i,p,j-2);
            
          bool use = (s[i] == p[j - 1] || p[j - 1] == '.') && match(s, i - 1, p, j);

            return ignore || use;
        }

        return 0;

    }
    bool isMatch(string s, string p) {
        int n= s.size();
        int m= p.size();

        return match(s,n-1,p,m-1);
    }
};
