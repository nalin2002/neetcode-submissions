class MinStack {
private:
    stack<int> st;
    stack<int> minst;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        int currmin= minst.empty()? val: min(val,minst.top());
        minst.push(currmin);
    }
    
    void pop() {
        st.pop();
        minst.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minst.top();
    }
};
