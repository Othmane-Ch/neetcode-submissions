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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        DSU dsu(accounts.size());
        unordered_map<string, vector<int>> mp {};
        for(int i = 0; i < accounts.size(); ++i)
        {
            for(int j = 1; j < accounts[i].size(); ++j)
            {
                mp[accounts[i][j]].push_back(i);
            }
        }

        for(const auto& [_, v] : mp)
        {
            if(v.size() > 1)
            {
                for(int i = 1; i < v.size(); ++i)
                {
                    dsu.unionSet(v[0], v[i]);
                }
            }
        }
        unordered_map<int, set<string>> mp_aux {};
        for(int i = 0; i < accounts.size(); ++i)
        {
            for(int j = 1; j < accounts[i].size(); ++j)
            {
                mp_aux[dsu.find(i)].insert(accounts[i][j]);
            }
        }
        
        vector<vector<string>> result(dsu.getCount());
        int i = 0;
        for(const auto& [idx , emails] : mp_aux)
        {
            result[i].push_back(accounts[idx][0]);
            result[i].insert(result[i].end(), emails.begin(), emails.end());
            ++i;
        }
        return result; 
    }
};