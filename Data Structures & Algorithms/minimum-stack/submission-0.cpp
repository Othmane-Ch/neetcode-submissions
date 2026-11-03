class MinStack {
private:
    stack<int> st;
    stack<int> min_st;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        int min_val = min_st.empty() ? val : min(min_st.top(), val);
        min_st.push(min_val);
    }
    
    void pop() {
        if(!st.empty() && !min_st.empty())
        {
            st.pop();
            min_st.pop();
        }   
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return min_st.top();
    }
};
