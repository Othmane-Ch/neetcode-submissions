class Solution {
public:
    // Time  : O(n * l + n + l) 
    // Space : O(n + l)
    string foreignDictionary(vector<string>& words) {
        unordered_map<char, vector<char>> adjList {};
        unordered_map<char, int> indegree {};
        for(const auto& word : words)
        {
            for(char c : word)
            {
                indegree[c];          // inserts c with value 0 if it isn't there yet
                adjList[c];           // optional: gives every letter an (empty) list
            }
        }
        for(int i = 0; i < words.size() - 1; ++i)
        {
            int len = min(words[i].size(), words[i+1].size());
            for(int j = 0; j < len; ++j)
            {
                if(words[i + 1][j] == words[i][j]) continue;
                adjList[words[i][j]].push_back(words[i+1][j]);
                ++indegree[words[i + 1][j]];
                break;
            }
            if(words[i + 1].size() < words[i].size() && words[i].compare(0, len, words[i + 1]) == 0)
            {
                return "";
            }
        }
        queue<char> q {};
        for(const auto& [c, i] : indegree)
        {
            if(i == 0)
            {
                q.push(c);
            }
        }
        
        string result {};
        while(!q.empty())
        {
            auto c = q.front(); q.pop();
            result.push_back(c);
            for(int i = 0; i < adjList[c].size(); ++i)
            {
                if(--indegree[adjList[c][i]] == 0)
                {
                    q.push(adjList[c][i]);
                }
            }
        }
        return result.size() == indegree.size() ? result : ""; 
    }
};
