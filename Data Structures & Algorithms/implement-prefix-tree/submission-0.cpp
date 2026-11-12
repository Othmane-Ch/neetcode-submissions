class PrefixTree {
private:
    bool is_word = false;
    unordered_map<char, PrefixTree *> mp{};

public:
    PrefixTree() = default;
    PrefixTree(bool b) : is_word(b) {}
    
    void insert(string word) {
        const int n = word.size();
        auto curr = &mp;
        for(int i = 0; i < n; ++i)
        {
            auto it = curr->find(word[i]);
            if(it == curr->end())
            {
                auto node = new PrefixTree();
                (*curr)[word[i]] = node;
            }
            if(i == n-1) (*curr)[word[i]]->is_word = true;
            curr = &((*curr)[word[i]]->mp);
        }
    }
    
    bool search(string word) {
        const int n = word.size();
        auto curr = &mp;
        bool res = false;
        for(int i = 0; i < n; ++i)
        {
            auto it = curr->find(word[i]);
            if(it == curr->end())
            {
                return false;
            }
            if(i == n-1) res = it->second->is_word;
            curr = &(it->second->mp);
        }
        return res;
    }
    
    bool startsWith(string prefix) {
        const int n = prefix.size();
        auto curr = &mp;
        for(int i = 0; i < n; ++i)
        {
            auto it = curr->find(prefix[i]);
            if(it == curr->end())
            {
                return false;
            }
            curr = &(it->second->mp);
        }
        return true;    
    }
};
