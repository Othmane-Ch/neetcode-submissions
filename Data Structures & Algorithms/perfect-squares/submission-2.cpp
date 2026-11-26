class Solution {
public:
    int numSquares(int n) {
        vector<int> squares {};
        for(int i = 1; i < n; ++i)
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
        dp[1] = 1;
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