class DSU {
private :
    int count;
    vector<int> root, rank;
public:
    DSU(int n) : count(n), root(n), rank(n, 1)
    {
        for(int i = 0; i < n; ++i)
        {
            root[i] = i;
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

    int getCount() { return count;}
};
class Solution {
public:
    // Time  : O(n² logn)
    // Space : O(n²)
    int minCostConnectPoints(vector<vector<int>>& points) {
        const int n = points.size();
        vector<tuple<int, int, int>> edges {};
        for(int i = 0; i < n; ++i)
        {
            for(int j = i + 1; j < n; ++j)
            {
                int distance = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edges.push_back(make_tuple(distance, i, j));
            }
        }

        sort(edges.begin(), edges.end());
        int cost = 0;
        DSU dsu(n);
        for(int i = 0; i < edges.size(); ++i)
        {
            if(dsu.getCount() == 1) break;
            auto& [w, u, v] = edges[i];
            if(dsu.unionSet(u, v))
            {
                cost += w;
            }
        }

        return cost;
        
    }
};
