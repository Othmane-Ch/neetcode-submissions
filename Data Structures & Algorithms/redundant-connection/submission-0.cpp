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
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        DSU dsu(edges.size());
        vector<int> res {};
        for(const auto& edge : edges)
        {
            if(!dsu.unionSet(edge[0] - 1, edge[1] - 1))
            {
                return edge;
            }    
        }
        return {};
    }
};
