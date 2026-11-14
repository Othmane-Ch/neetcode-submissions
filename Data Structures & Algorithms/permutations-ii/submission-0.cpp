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
            if((i > 0 && nums[i-1] == nums[i] && !indices.contains(i - 1)) || indices.contains(i) ) continue;
            combo.push_back(nums[i]);
            indices.insert(i);
            dfs(indices, nums, combo, result);
            combo.pop_back();
            indices.erase(i);
        }
    }


    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result {};
        vector<int> combo {};
        unordered_set<int> indices {};
        dfs(indices, nums, combo, result);
        return result;
    }
};