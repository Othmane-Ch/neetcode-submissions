class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, 0); // number of combination in nums that sums to i
        const int n = nums.size();
        dp[0] = 1;
        for(int i = 1; i <= target; ++i)
        {
            for(const auto& num : nums)
            {
                if(i < num) continue;
                dp[i] += dp[i - num];
            }
        }
        return dp[target];
    }
};