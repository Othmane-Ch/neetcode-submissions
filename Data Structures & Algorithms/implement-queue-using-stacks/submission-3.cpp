class MyQueue {

private:
    stack<int> st, st_aux;
    
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        st.push(x);
    }
    // Time : O(n) for the first pop, rest in O(1) 
    int pop() {
        if(st_aux.empty())
        {
            while(!st.empty())
            {
                st_aux.push(st.top());
                st.pop();
            }
        }
        int res = st_aux.top();
        st_aux.pop();
        return res;
    }
    
    int peek() {
        if(st_aux.empty())
        {
            while(!st.empty())
            {
                st_aux.push(st.top());
                st.pop();
            }
        }
        int res = st_aux.top();
        return res;
    }
    
    bool empty() {
        return st.empty() && st_aux.empty(); 
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