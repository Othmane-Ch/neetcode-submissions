class DSU {
private:
    int count;
    vector<int> root, rank;
public:
    DSU(int n) : root(n) , rank(n), count(n)
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
    // true if a merge happened; false if x and y were already connected
    bool unionSet(int x, int y)
    {
        int rootX = find(x), rootY = find(y);
        if(rootX == rootY) return false;
        if(rank[rootX] > rank[rootY])
        {
            root[rootY] = rootX;
        } else if(rank[rootX] < rank[rootY])
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

    bool isConnected(int x, int y)
    {
        return find(x) == find(y);
    }
};
class Solution {
public:
    // DSU
    bool validTree(int n, vector<vector<int>>& edges) {
        DSU dsu(n);
        for(const auto& edge : edges)
        {
            if(!dsu.unionSet(edge[0], edge[1]))
            {
                return false;
            }
        }
        return dsu.getCount() == 1;
    }
};
