class Solution {
public:

    void dfs(int idx, vector<int> & subset, const vector<int>& nums, vector<vector<int>> & result)
    {
        if(idx >= nums.size())
        {
            result.push_back(subset);
            return;
        }
        // Include it
        subset.push_back(nums[idx]);
        dfs(idx + 1, subset, nums, result);
        // Exclude and skip all duplicates
        while(idx < nums.size() - 1 && nums[idx] == nums[idx + 1])
        {
            ++idx;
        }
        subset.pop_back();
        dfs(idx + 1, subset, nums, result);
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result {};
        vector<int> subset {};
        dfs(0, subset, nums, result);
        return result;
    }
};
