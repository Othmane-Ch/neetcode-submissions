class Solution {
public:

    // Time: O(U) recursive calls, excluding result copying
    // Auxiliary Space: O(n)
    void dfs(int idx,
             const vector<int>& nums,
             const vector<int>& nextDifferent,
             vector<int>& subset,
             vector<vector<int>>& result)
    {
        int n = nums.size();

        if(idx == n)
        {
            result.push_back(subset);
            return;
        }

        // Include current element
        subset.push_back(nums[idx]);
        dfs(idx + 1, nums, nextDifferent, subset, result);
        subset.pop_back();

        // Exclude current element and all its duplicates
        dfs(nextDifferent[idx], nums, nextDifferent, subset, result);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        int n = nums.size();

        sort(nums.begin(), nums.end()); // Time: O(n log n)

        // nextDifferent[i] = first index after the group of nums[i]
        vector<int> nextDifferent(n, n);

        // Precompute duplicate-group boundaries
        // Time: O(n), Space: O(n)
        for(int i = n - 2; i >= 0; --i)
        {
            if(nums[i] == nums[i + 1])
                nextDifferent[i] = nextDifferent[i + 1];
            else
                nextDifferent[i] = i + 1;
        }

        vector<vector<int>> result;
        vector<int> subset;

        dfs(0, nums, nextDifferent, subset, result);

        return result;
    }
};