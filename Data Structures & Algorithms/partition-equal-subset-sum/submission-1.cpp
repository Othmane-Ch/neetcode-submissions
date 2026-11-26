class Solution {
public:
    // Time  : O(s * n + n) s == sum/2
    // Space : O(s * n)
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2 == 1) return false;
        const int n = nums.size();
        const int target = sum / 2;
        vector<vector<bool>> dp(n + 1,vector<bool>(target + 1, false)); // can a subset of nums[0..i] reach s
        dp[0][0] = true;
        for(int i = 1; i <= nums.size(); ++i)
        {
            for(int s = 0; s <= (sum / 2); ++s) 
            {
                dp[i][s] = dp[i - 1][s] || (s >= nums[i - 1] && dp[i - 1][s - nums[i - 1]]);
            }
        }
        return dp[nums.size()][sum / 2];
    }
};
