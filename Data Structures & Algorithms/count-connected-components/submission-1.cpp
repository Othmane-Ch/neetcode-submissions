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

    void unionSet(int x, int y)
    {
        int rootX = find(x), rootY = find(y);
        if(rootX == rootY) return ;
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
    }

    int getCount()
    {
        return count;
    }
};

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        DSU dsu(n);
        for(const auto& edge : edges)
        {
            dsu.unionSet(edge[0], edge[1]);
        }

        return dsu.getCount();
    }
};
