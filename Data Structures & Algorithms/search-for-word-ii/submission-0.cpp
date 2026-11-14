struct TrieNode {
    bool isWord = false;
    int idx = -1;
    array<TrieNode*, 26> children {};
    TrieNode() = default;

    TrieNode * walk(const string& word)
    {
        auto curr = this;
        for(char c : word)
        {
            if(!curr->children[c - 'a'])
            {
                return nullptr;
            }
            curr = curr->children[c - 'a'];
        }
        return curr;
    }
};

class Trie {
public:
    TrieNode * root {};

    Trie(const auto& words) 
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
            curr->isWord = true;
            curr->idx = i;
        }
    }

    bool search(const string& word)
    {
        auto node = root->walk(word);
        return node && node->isWord;
    }

    bool startWith(const string& prefix)
    {
        return root->walk(prefix) != nullptr;
    }
};

class Solution {

private:

    vector<pair<int, int>> getNeighbors(const pair<int, int>& point, int rows, int cols, const vector<vector<bool>>& seen)
    {
        auto [x, y] = point;
        array<int, 4> dx = {0, 0, -1, 1};
        array<int, 4> dy = {-1, 1, 0, 0};
        vector<pair<int, int>> result {};
        for(int i = 0; i < 4; ++i)
        {
            if( 0 <= x + dx[i] && x + dx[i] < rows && 0 <= y + dy[i] && y + dy[i] < cols && !seen[x + dx[i]][y + dy[i]])
            {
                result.push_back(make_pair(x + dx[i], y + dy[i]));
            }
        }
        return result;
    }

    void dfs(const vector<vector<char>>& board,
            const vector<string>& words,
            const pair<int, int>& point, 
            TrieNode * node, 
            vector<string>& result, 
            vector<vector<bool>>& seen)
    {
        const int rows = board.size();
        const int cols = board[0].size();

        if(seen[point.first][point.second])
        {
            return;
        }
        auto next_node = node ? node->walk(string(1, board[point.first][point.second])) : nullptr;
        if(!next_node)
        {
            return;
        }

        if(next_node->isWord)
        {
            result.push_back(words[next_node->idx]);
            next_node->isWord = false;
        }  
        seen[point.first][point.second] = true;
        auto neighbors = getNeighbors(point, rows, cols, seen);
        for(const auto& neighbor : neighbors)
        {
            dfs(board, words, neighbor, next_node, result, seen);
        }
        seen[point.first][point.second] = false;
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        const int rows = board.size();
        const int cols = board[0].size();
        vector<string> result {};
        Trie trie(words);
        vector<vector<bool>> seen(rows, vector<bool>(cols, false));
        for(int r = 0; r < rows; ++r)
        {
            for(int c = 0; c < cols; ++c)
            {
                auto point = make_pair(r, c);
                dfs(board, words, point, trie.root, result, seen);
            }
        }
        return result;
    }
};
