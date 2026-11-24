class DSU {
private :
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

    int getCount() {return count;}
};
class Solution {
public:
    // Time  : O(ElogE + E²)
    // Space : O(E + )
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        for(int i = 0; i < edges.size(); ++i)
        {
            edges[i].push_back(i);
        }
        sort(edges.begin(), edges.end(), [](const auto& v1, const auto& v2){
            return v1[2] < v2[2];
        });

        DSU dsu(n);
        int mst_weight = 0;
        for(int i = 0; i < edges.size(); ++i)
        {
            int u = edges[i][0], v = edges[i][1], w = edges[i][2];
            if(dsu.unionSet(u, v))
            {
                mst_weight += w;
            } 
        }

        vector<int> critical {};
        vector<int> pseudo {};

        for(int i = 0; i < edges.size(); ++i)
        {
            const int u = edges[i][0], v = edges[i][1], w = edges[i][2], idx = edges[i][3];
            DSU uf(n);
            // Forbid edge
            int weight = 0;
            for(int j = 0; j < edges.size(); ++j)
            {
                if(j == i) continue;
                if(uf.unionSet(edges[j][0], edges[j][1]))
                {
                    weight +=  edges[j][2];
                } 
            }
            if(uf.getCount() != 1 || weight > mst_weight)
            {
                critical.push_back(idx);
                continue;
            }
            // Force Edge
            DSU ufs(n);
            ufs.unionSet(u, v);
            weight = w;
            for(int j = 0; j < edges.size(); ++j)
            {
                if(ufs.unionSet(edges[j][0], edges[j][1]))
                {
                    weight +=  edges[j][2];
                } 
            }           
            if(weight == mst_weight)
            {
                pseudo.push_back(idx);
            }
        }

        return {critical, pseudo};
    }
};