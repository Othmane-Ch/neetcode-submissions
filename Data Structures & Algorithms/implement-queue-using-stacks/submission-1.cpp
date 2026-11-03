class MyQueue {

private:
    stack<int> st{};
    stack<int> st_aux{};
    
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        st.push(x);
    }
    // Time : O(n) + O(n)
    int pop() {
        while(!st.empty())
        {
            int num = st.top();
            st.pop();
            st_aux.push(num);
        }

        int res = st_aux.top();
        st_aux.pop();
        while(!st_aux.empty())
        {
            int num = st_aux.top();
            st_aux.pop();
            st.push(num);
        }
        return res;
    }
    
    int peek() {
        stack<int> st_aux{};
        while(!st.empty())
        {
            int num = st.top();
            st.pop();
            st_aux.push(num);
        }

        int res = st_aux.top();
        while(!st_aux.empty())
        {
            int num = st_aux.top();
            st_aux.pop();
            st.push(num);
        }
        return res;
    }
    
    bool empty() {
        return st.empty(); 
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */