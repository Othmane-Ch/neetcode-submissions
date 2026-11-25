struct TrieNode {
    bool isWord = false;
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
            curr->isWord = true;
        }
    }

    bool search(const string& word)
    {
        cout << word << endl;
        auto curr = root;
        for(char c : word)
        {
            if(!curr->children[c - 'a']) return false;
            curr = curr->children[c - 'a'];
        }
        return curr->isWord;
    }
};

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        const int n = s.size();
        Trie trie(wordDict);
        vector<bool> dp(n + 1, false);
        dp[0] = true;

        for (int i = 0; i < n; ++i) {
            if (!dp[i]) continue;                          // no word can start here
            TrieNode* curr = trie.root;
            for (int k = i; k < n; ++k) {            // walk s[i], s[i+1], ... (bounded by n)
                curr = curr->children[s[k] - 'a'];
                if (!curr) break;                    // no dictionary word continues this way
                if (curr->isWord) dp[k + 1] = true;  // s[i..k] is a word
            }
        }
        return dp[n];
    }
};
