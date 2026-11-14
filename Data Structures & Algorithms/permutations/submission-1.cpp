class Solution {
public:
    // Time  : o(n * n!)
    // Space : o(n)
    void dfs(unordered_set<int> & indices, const vector<int>& nums, vector<int>& combo, vector<vector<int>>& result)
    {
        if(indices.size() == nums.size())
        {
            result.push_back(combo);
            return;
        }
        // o(n)
        for(int i = 0; i < nums.size(); ++i)
        {
            if(indices.contains(i)) continue;
            combo.push_back(nums[i]);
            indices.insert(i);
            dfs(indices, nums, combo, result);
            combo.pop_back();
            indices.erase(i);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result {};
        vector<int> combo {};
        unordered_set<int> indices {};
        dfs(indices, nums, combo, result);
        return result;
    }
};