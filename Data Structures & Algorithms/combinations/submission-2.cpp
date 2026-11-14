class Solution {
public:

    void dfs(int idx, int n, int k, vector<int>& combo, vector<vector<int>>& result)
    {
        if(combo.size() == k)
        {
            result.push_back(combo);
            return;
        }

        for(int i = idx; i <= n; ++i)
        {
            combo.push_back(i);
            dfs(i + 1, n, k, combo, result);
            combo.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result {};
        vector<int> combo {};
        dfs(1, n, k, combo, result);
        return result;
    }
};