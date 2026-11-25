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
        unordered_set<string> words(wordDict.begin(), wordDict.end());
        for (int j = 1; j <= n; ++j) {
            for (int i = 0; i < j; ++i) {        // every split point
                // last word = s[i..j-1], everything before it = s[0..i-1]
                if (words.contains(s.substr(i, j - i)) && dp[i]) {
                    dp[j] = true;
                    break;                       // one valid split is enough
                }
            }
        }
        return dp[n];
    }
};
