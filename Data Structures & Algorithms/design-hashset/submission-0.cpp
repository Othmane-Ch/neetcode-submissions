class MyHashSet {
private:
 std::vector<int> elements;
public:
    MyHashSet() {
    
    }
    
    void add(int key) {
        if(!contains(key))
        {
            elements.push_back(key);
        }
    }
    
    void remove(int key) {
        if(!contains(key))
        {
            return;
        }
        const int n = elements.size();
        std::vector<int> new_elements;
        for(auto i = 0; i < n; ++i)
        {
            if(elements[i] != key)
            {
                new_elements.push_back(elements[i]);
            }
        }
        elements = new_elements;
    }
    
    bool contains(int key) 
    {
        cout << "Contains" << endl;
        auto it = std::find(elements.begin(), elements.end(), key);
        for(auto i = 0; i < elements.size(); ++i)
        {
            cout << elements[i] << endl;
        }
        return it != elements.end();
    }
};