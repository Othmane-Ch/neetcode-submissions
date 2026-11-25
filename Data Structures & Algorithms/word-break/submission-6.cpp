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

    bool search(const string& word)
    {
        auto curr = root;
        for(char c : word)
        {
            if(!curr->children[c - 'a']) return false;
            curr = curr->children[c - 'a'];
        }
        return curr->size != 0;
    }
};

class Solution {
public:
    // DP-Bottom-Top
    // Time  : O(d * l + n * d )
    // Space : O(n + d * l) l max word in dict
    bool wordBreak(string s, vector<string>& wordDict) {
        const int n = s.size();
        Trie trie(wordDict);
        vector<bool> dp(n + 1, false);
        dp[n] = true;
        for(int i = n - 1; i >= 0; --i)
        {
            if(!trie.root->children[s[i] - 'a']) continue;
            auto curr = trie.root;
            for(int j = i; j < n; ++j)
            {
                if(!curr->children[s[j] - 'a']) break;
                curr = curr->children[s[j] - 'a'];
                if(curr->size != 0 && dp[i + curr->size])
                {
                    dp[i] = true;
                }
            }
        }

        return dp[0];
    }
};
