class MyHashMap {
private:
    vector<pair<int, int>> vPairs;
public:
    MyHashMap() {}
    
    void put(int key, int value) {
        auto it = std::find_if(vPairs.begin(), vPairs.end(), [key](const auto& item){return item.first == key;});
        if(it != vPairs.end())
        {
            it->second = value;
        } 
        else 
        {
            vPairs.push_back(make_pair(key, value));
        }
    }
    
    int get(int key) {
        int result = -1;
        auto it = std::find_if(vPairs.begin(), vPairs.end(), [key](const auto& item){return item.first == key;});
        if(it != vPairs.end())
        {
            result = it->second;
        } 
        return result;
    }
    
    void remove(int key) {
        auto it = std::find_if(vPairs.begin(), vPairs.end(), [key](const auto& item){return item.first == key;});
        if(it != vPairs.end())
        {
            // Swap and pop - o(1)
            std::iter_swap(it, vPairs.end() - 1);
            vPairs.pop_back();
        }
    }
};

/**
 * n number of pairs
 * Time complexity : each function has o(n)
 * Space complexity : o(n)
 */

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */