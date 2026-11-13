class Solution {

private:
    struct TrieNode {
        bool isWord = false;
        array<TrieNode *, 26> children {};
        TrieNode() = default;
    };

    struct Trie {
        TrieNode * root {};
        Trie()
        {
            root = new TrieNode();
        }

        void add(string word)
        {
            auto curr = root;
            for(char c : word)
            {
                if(!curr->children[c - 'a'])
                {
                    curr->children[c - 'a'] = new TrieNode();
                }
                curr = curr->children[c - 'a'];
            }
            curr->isWord = true;
        }

        bool search(string word)
        {
            auto curr = root;
            for(char c : word)
            {
                if(!curr->children[c - 'a'])
                {
                    return false;
                }
                curr = curr->children[c - 'a'];
            }
            return curr->isWord;
        }

        int breakWord(const string& s) {
            const int n = s.size();
            vector<int> dp(n + 1);
            dp[n] = 0;
            for (int i = n - 1; i >= 0; --i) {
                dp[i] = 1 + dp[i + 1];
                TrieNode* curr = root;
                for (int j = i; j < n; ++j) {
                    if(!curr->children[s[j] - 'a'])
                    {
                        break;
                    }
                    curr = curr->children[s[j] - 'a'];
                    if(curr->isWord)
                    {
                        dp[i] = min(dp[i], dp[j+1]);
                    }
                    
                }
            }
            return dp[0];
        }

    };
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        Trie  trie;
        for(const auto& word : dictionary)
        {
            trie.add(word);
        }

        return trie.breakWord(s);
    }
};