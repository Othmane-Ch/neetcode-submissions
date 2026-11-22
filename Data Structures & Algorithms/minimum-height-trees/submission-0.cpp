class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(n);
        for(const auto& edge : edges)
        {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
        vector<int> heights(n);
        int min_height = INT_MAX;
        for(int i = 0; i < n; ++i)
        {
            queue<tuple<int, int, int>> q {};
            q.push(make_tuple(i, -1, 0));
            int h = 0;
            while(!q.empty())
            {
                auto [node, parent, height] = q.front(); q.pop();
                h = max(h, height);
                for(int j = 0; j < adjList[node].size(); ++j)
                {
                    if(adjList[node][j] == parent) continue;
                    q.push(make_tuple(adjList[node][j], node, height + 1));
                }
            }
            heights[i] = h;
            min_height = min(min_height, h);
        }
        vector<int> result {};

        for(int i = 0; i < n; ++i)
        {   
            if(heights[i] == min_height)
            {
                result.push_back(i);
            }
        }
        return result;
    }
};