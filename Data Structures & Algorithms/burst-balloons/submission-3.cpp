class Solution {
public:
    // Interval-DP Top-Down
    // Time  : O(n^3)
    // Space : O(n²)
    int maxCoins(vector<int>& nums) {
        const int n = nums.size();
        vector<vector<int>> memo(n + 2, vector<int>(n + 2, -1));
        auto dfs = [&] (this auto&& self, int start, int end) -> int
        {
            if(end == start + 1)
            {
                return 0;
            }
            if(memo[start + 1][end + 1] != -1) return memo[start + 1][end + 1];
            int prev = start == -1 ? 1 : nums[start];
            int next = end  == n ? 1 : nums[end];
            int res = 0;
            for(int k = start + 1; k < end; ++k)
            {
                int coins = prev * nums[k] * next;           
                res = max(res, self(start, k) + coins + self(k, end));
            }
            return memo[start + 1][end + 1] = res;
        };        
        return dfs(-1, n);
    }
};
