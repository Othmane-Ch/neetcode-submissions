class Solution {
public:

    void dfs(int idx, int sum, int target, vector<int> subset, const vector<int>& nums, vector<vector<int>>& result)
    {
        if(sum > target) return;
        if(sum == target)
        {
            result.push_back(subset);
            return;
        }

        for(int i = idx; i < nums.size(); ++i)
        {
            subset.push_back(nums[i]);
            dfs(i, sum + nums[i], target, subset, nums, result);
            subset.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> result {};
        dfs(0, 0, target, {}, nums, result);
        return result;
    }
};
