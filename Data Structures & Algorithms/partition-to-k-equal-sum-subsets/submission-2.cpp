class Solution {
public:
    // Time  : O(k^n)
    // Space : O(n)
    bool dfs(int idx, int target, const std::vector<int>& nums, vector<int>& subsets)
    {
        if(idx == nums.size())
        {
            return true;
        }

        for(int i = 0; i < subsets.size(); ++i)
        {
            if(subsets[i] + nums[idx] <= target)
            {
                subsets[i] += nums[idx];
                if(dfs(idx + 1, target, nums, subsets))
                {
                    return true;
                }
                subsets[i] -= nums[idx];
            }
            if(subsets[i] == 0) break;
        }
        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        sort(nums.rbegin(), nums.rend());
        int perim = accumulate(nums.begin(), nums.end(), 0);
        int target = perim / k;
        double d_t = static_cast<double>(perim) / k;
        if(static_cast<double>(target) != d_t) return false;
        vector<int> subsets(k, 0); 
        return dfs(0, target, nums, subsets);
    }
};