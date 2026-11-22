class DSU {
private:
    int count;
    vector<int> root, rank;
    vector<double> weight;
public:
    DSU(int n) : count(n), root(n), rank(n), weight(n)
    {
        for(int i = 0; i < n; ++i)
        {
            root[i] = i;
            rank[i] = 1;
            weight[i] = 1.0;
        }
    }

    int find(int x)
    {
        if(root[x] == x)
        {
            return x;
        }
        int parent = root[x];
        root[x] = find(parent);
        weight[x] *= weight[parent];
        return root[x];
    }

    bool unionSet(int x, int y, double value)               // records x / y = value
    {
        int rootX = find(x), rootY = find(y);
        if(rootX == rootY) return false;
        if(rank[rootX] > rank[rootY])
        {
            root[rootY] = rootX;
            weight[rootY] = weight[x] / (value * weight[y]);    // + rootY / rootX
        } else if(rank[rootY] > rank[rootX])
        {
            root[rootX] = rootY;
            weight[rootX] = value * weight[y] / weight[x];      // + rootX / rootY
        } else {
            root[rootY] = rootX;
            weight[rootY] = weight[x] / (value * weight[y]);    // + rootY / rootX
            ++rank[rootX];
        }
        --count;
        return true;
    }

    double ratio(int x, int y)
    {
        if(find(x) != find(y)) return -1;
        return weight[x] / weight[y];
    }

};

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, int> indices {};
        int idx = 0;
        for(const auto& equation : equations)
        {
            if(!indices.contains(equation[0]))
            {
                indices[equation[0]] = idx;
                ++idx;
            }
            if(!indices.contains(equation[1]))
            {
                indices[equation[1]] = idx;
                ++idx;
            }
        }

        DSU dsu(indices.size());
        for(int i = 0; i < equations.size(); ++i)
        {
            dsu.unionSet(indices[equations[i][0]], indices[equations[i][1]], values[i]);
        }
        vector<double> result(queries.size());
        for(int i = 0; i < queries.size(); ++i)
        {
            if(!indices.contains(queries[i][0]) || !indices.contains(queries[i][1]))
            {
                result[i] = -1.0;
            } else {
                result[i] = dsu.ratio(indices[queries[i][0]], indices[queries[i][1]]);
            }
        }
        return result;
    }
};