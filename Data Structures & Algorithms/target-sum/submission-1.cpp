struct PairHash {
    size_t operator()(const pair<int, int>& p) const {
        return hash<long long>()(((long long)p.first << 32) | (unsigned int)p.second);
    }
};
class Solution {
public:

    int dfs(const pair<int, int>& p, vector<int>& nums, unordered_map<pair<int, int>, int, PairHash>& dp)
    {
        auto& [i, rem] = p;
        if(i == nums.size())
        {
            if(rem == 0)
            {
                return 1;
            }
            return 0;
        }
        if(dp.contains(p)) return dp[p];
        
        auto pos = make_pair(i + 1, rem + nums[i]);
        auto neg = make_pair(i + 1, rem - nums[i]);

        int res = dfs(pos, nums, dp) + dfs(neg, nums, dp);

        return  dp[p] = res;
    }
    // Memoization
    // Time  : O(n)
    // Space : O(n)
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<pair<int, int>, int, PairHash> dp {}; // key = (index , remaining to target) , v = number of ways to that target
        return dfs(make_pair(0, target), nums, dp);
    }
};
