class Solution {
public:
    bool isValid(string s) {
        int n=s.size();
        stack<char> st;
        for(int i=0;i<n;i++){
            if(st.empty()){
                st.push(s[i]);
            }
            else{
                char c = st.top();
                if(s[i]==')'){
                   c=='('? st.pop(): st.push(s[i]); 
                }
                else if(s[i]=='}'){
                   c=='{'? st.pop(): st.push(s[i]); 
                }
                else if(s[i]==']'){
                   c=='['? st.pop(): st.push(s[i]); 
                }
                else{
                    st.push(s[i]);
                }
            }
        }

        return st.size()==0;
    }
};
