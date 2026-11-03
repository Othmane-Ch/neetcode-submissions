class StockSpanner {
private:
    vector<int> prices;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        if(prices.empty())
        {
            prices.push_back(price);
            return 1;
        } else {
            int i = prices.size() - 1;
            while(i >= 0 && price >= prices[i])
            {
                --i;
            }
            prices.push_back(price);
            return prices.size() - 1 - i;
        }
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */