class StockSpanner {
private:
    stack<pair<int, int>> st;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        if(st.empty())
        {
            st.push(make_pair(price, 1));
            return 1;
        } else {
            int i = 1;
            while(!st.empty() && st.top().first <= price)
            {
                i += st.top().second;
                st.pop();
            }
            st.push(make_pair(price, i));
            return i;
        }
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */