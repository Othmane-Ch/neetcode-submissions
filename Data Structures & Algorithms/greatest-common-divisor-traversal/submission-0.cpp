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
    bool canTraverseAllPairs(vector<int>& nums) {
        const int n = nums.size();
        DSU dsu(n);
        for(int i = 0; i < n; ++i)
        {
            for(int j = i + 1; j < n; ++j)
            {
                if(gcd(nums[i], nums[j]) > 1)
                {
                    dsu.unionSet(i, j);
                }
            }
        }

        return dsu.getCount() == 1;
    }
};