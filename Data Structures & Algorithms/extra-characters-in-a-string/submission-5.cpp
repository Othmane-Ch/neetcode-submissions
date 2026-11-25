struct TrieNode {
    int size = 0;
    array<TrieNode*, 26> children {};
    TrieNode() = default; 
};

class Trie {
public:
    TrieNode * root {};
    Trie(const vector<string>& wordDict)
    {
        root = new TrieNode();
        for(int i = 0; i < wordDict.size(); ++i)
        {
            auto curr = root;
            for(char c : wordDict[i])
            {
                if(!curr->children[c - 'a'])
                {
                    curr->children[c - 'a'] = new TrieNode();
                }
                curr = curr->children[c - 'a'];
            }
            curr->size = wordDict[i].size();
        }
    }
};

class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        const int n = s.size();
        Trie trie(dictionary);
        vector<int> dp(n + 1, 0);
        for(int j = n - 1; j >= 0; --j)
        {
            dp[j] = 1 + dp[j + 1];
            auto curr = trie.root;
            for(int i = j; i < n; ++i)
            {
                if(!curr->children[s[i] - 'a']) break;
                curr = curr->children[s[i] - 'a'];
                if(curr->size)
                {
                    dp[j] = min(dp[j], dp[j + curr->size]); // s[j..i] is  word
                }
            }
        }
        return dp[0];
    }
};