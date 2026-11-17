struct TrieNode {
    int idx = -1;
    array<TrieNode*, 26> children {};
    TrieNode() = default;
};

struct Trie {
    TrieNode * root {};

    Trie(const vector<string> words)
    {
        root = new TrieNode();
        for(int i = 0; i < words.size(); ++i)
        {
            auto curr = root;
            for(char c : words[i])
            {
                if(!curr->children[c - 'a'])
                {
                    curr->children[c - 'a'] = new TrieNode();
                }
                curr = curr->children[c - 'a'];
            }
            curr->idx = i;
        }
    }
};

class Solution {
private:
    void dfs(int k, string& sub, const string& s, TrieNode * node, vector<string>& wordDict, vector<string>& result)
    {
        if(k == s.size())
        {
            sub.pop_back();
            result.push_back(sub);
            return;
        }
        auto curr = node;
        for(int i = k; i < s.size(); ++i)
        {
            if(!curr->children[s[i] - 'a']) break;

            curr = curr->children[s[i] - 'a'];
            if(curr->idx != -1) 
            {
                const auto old_size = sub.size();
                sub +=  wordDict[curr->idx] + " ";
                dfs(i + 1, sub, s, node, wordDict, result);
                sub.resize(old_size);
            }
        }

    }

public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        Trie trie(wordDict);
        vector<string> result {};
        string sub {};
        dfs(0, sub, s, trie.root, wordDict, result);
        return result;
    }
};