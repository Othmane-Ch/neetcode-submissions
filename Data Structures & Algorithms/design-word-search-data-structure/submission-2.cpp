struct TrieNode {
    bool isWord = false;
    array<TrieNode*, 26> children {};
    TrieNode() = default;


};

class WordDictionary {
private:
    TrieNode * root {};
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        auto curr = root;
        for(char c : word)
        {
            int i = c - 'a';
            if(!curr->children[i])
            {
                auto node = new TrieNode();
                curr->children[i] = node;
                curr = node;
            } else {
                curr = curr->children[i];
            }
        }
        curr->isWord = true;
    }
    
    bool subSearch(string word, TrieNode * node)
    {
        const int n = word.size();
        auto curr = node;
        for(int i = 0; i < word.size(); ++i)
        {
            if(word[i] == '.')
            {
                for(auto child : curr->children)
                {
                    if(child && subSearch(word.substr(i + 1), child))
                    {
                        return true;
                    }
                }
                return false;
            } 
            else if(!curr->children[word[i] - 'a'])
            {
                return false;
            } 
            else 
            {
                curr = curr->children[word[i] - 'a'];
            }
        }
        
        return curr->isWord;
    }

    bool search(string word) {
        return subSearch(word, root);
    }
};
