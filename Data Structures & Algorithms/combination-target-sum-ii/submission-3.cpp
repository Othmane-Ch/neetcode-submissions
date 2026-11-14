class Solution {
public:


    void dfs(int idx, int sum, int target, vector<int> & combo, vector<int>& nums, vector<vector<int>> & result)
    {
        if(sum > target) return;
        if(sum == target)
        {
            result.push_back(combo);
            return;
        }
        int prev = -1;
        for(int i = idx; i < nums.size(); ++i) // n
        {
            if(nums[i] == prev) continue;
            prev = nums[i];
            combo.push_back(nums[i]);
            dfs(i + 1, sum + nums[i], target, combo, nums, result);
            combo.pop_back();
        }
    }
    // Time  : o(nlogn + n2^n)
    // Space : o(n)
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result {};
        vector<int>  combo {};
        sort(candidates.begin(), candidates.end()); // nlogn
        dfs(0, 0, target, combo, candidates, result);
        return result;
    }
};
