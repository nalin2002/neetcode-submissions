class Solution {
public:
    bool isPalindrome(string s) {
        int i=0,j=s.size()-1;
        int count =0;
        if(s.size()==0) return false;
        if(s.size()==1) return true;
        string temp="";
        for( auto x: s){
            if( isalnum(x))
            temp+=tolower(x);
        }
        return temp ==  string(temp.rbegin(),temp.rend());
    }
};
