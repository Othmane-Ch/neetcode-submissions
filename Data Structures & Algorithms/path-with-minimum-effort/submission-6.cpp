class DSU {
private:
    int count;
    vector<int> root, rank;
public:
    DSU(int n) : count(n), root(n), rank(n)
    {
        for(int i = 0; i < n; ++i)
        {
            root[i] = i;
            rank[i] = 1;
        }
    }

    int find(int x)
    {
        if(root[x] == x)
        {
            return x;
        }
        root[x] = find(root[x]);
        return root[x];
    }

    bool unionSet(int x, int y)
    {
        int rootX = find(x), rootY = find(y);
        if(rootX == rootY) return false;
        if(rank[rootX] > rank[rootY])
        {
            root[rootY] = rootX;
        } else if(rank[rootY] > rank[rootX])
        {
            root[rootX] = rootY;
        } else {
            root[rootY] = rootX;
            ++rank[rootX]; 
        }
        --count;
        return true;
    }

    int getCount()
    {
        return count;
    }
};

class Solution {
public:
    // Kruskal's
    int minimumEffortPath(vector<vector<int>>& heights) {
        int ROWS = heights.size();
        int COLS = heights[0].size();
        vector<tuple<int, int, int>> edges {};   // cost, u, v
        for(int r = 0; r  < ROWS; ++r)
        {
            for(int c = 0; c  < COLS; ++c)
            {
                // right
                int id = r * COLS + c;
                if(c + 1 < COLS)
                {
                    int cost_right = abs(heights[r][c + 1] - heights[r][c]);
                    edges.push_back({ cost_right, id, id + 1});
                }
                // bottom
                if(r + 1 < ROWS)
                {
                    int cost_bottom = abs(heights[r + 1][c] - heights[r][c]);
                    edges.push_back({ cost_bottom, id, id + COLS});
                }
            }
        }

        sort(edges.begin(), edges.end());
        DSU dsu(ROWS * COLS);
        const int start = 0, end = ROWS * COLS - 1;
        for(const auto& [diff, a, b] : edges)
        {
            dsu.unionSet(a, b);
            if(dsu.find(start) == dsu.find(end)) return diff;
        }
        return 0; 
    }
};