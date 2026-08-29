class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n= tokens.size();
        stack<string> st;
        for(int i=0;i<n;i++){
            if(tokens[i]!= "+" && tokens[i]!="-" && tokens[i]!="*" && tokens[i]!="/"){
                st.push(tokens[i]);
            }
            else{

                string top1s= st.top();
                int top1= stoi(top1s);
                st.pop();
                string top2s = st.top();
                int top2= stoi(top2s);
                st.pop();

                if( tokens[i]=="+"){
                    st.push(  to_string(top1+top2) ) ;
                }
                else if(tokens[i]== "-"){
                    st.push(  to_string(top2-top1) ) ;
                }
                else if(tokens[i]=="*"){
                    st.push(  to_string(top1*top2) ) ;
                }
                else if(tokens[i]=="/"){
                    st.push(  to_string(top2/top1) ) ;
                }
            }
        }
        return stoi(st.top());
    }
};
