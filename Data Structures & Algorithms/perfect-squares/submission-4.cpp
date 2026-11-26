class Solution {
public:
    // Similar to coin change
    // Time  : O(n * sqrt(n))
    // Space : O(n)
    int numSquares(int n) {
        vector<int> squares {};
        for(int i = 1; i <= n; ++i)
        {
            if(i * i <= n)
            {
                squares.push_back(i * i);
            } else {
                break;
            }
        }
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for(int i = 1; i <= n; ++i)
        {
            for(const auto& perfSquare : squares)
            {
                if(i < perfSquare) continue;
                dp[i] = min(dp[i], 1 + dp[i - perfSquare]);
            }
        }
        return dp[n];
    }
};