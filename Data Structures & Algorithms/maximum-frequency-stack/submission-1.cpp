class FreqStack {

private:
    unordered_map<int, int> count {};
    unordered_map<int, stack<int>> freq_stack{};
    int max_count {};
public:
    FreqStack() {
        
    }
    
    void push(int val) {
        ++count[val];
        max_count = max(max_count, count[val]);
        freq_stack[count[val]].push(val);
    }
    
    int pop() {
        int res = freq_stack[max_count].top();
        --count[res];
        freq_stack[max_count].pop();
        if(freq_stack[max_count].empty())
        {
            freq_stack.erase(max_count);
            --max_count;
        }
        
        return res;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */