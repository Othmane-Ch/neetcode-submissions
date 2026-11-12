class PrefixTree {
private:
    bool is_word = false;
    unordered_map<char, unique_ptr<PrefixTree>> children;

    const PrefixTree* walk(const string& s) const {
        const PrefixTree* node = this;
        for (char c : s) {
            auto it = node->children.find(c);
            if (it == node->children.end()) return nullptr;
            node = it->second.get();
        }
        return node;
    }

public:
    void insert(const string& word) {
        PrefixTree* node = this;
        for (char c : word) {
            auto& child = node->children[c];
            if (!child) child = make_unique<PrefixTree>();
            node = child.get();
        }
        node->is_word = true;
    }

    bool search(const string& word) const {
        const PrefixTree* node = walk(word);
        return node && node->is_word;
    }

    bool startsWith(const string& prefix) const {
        return walk(prefix) != nullptr;
    }
};