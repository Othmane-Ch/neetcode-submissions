class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        const int n = envelopes.size();
        sort(envelopes.begin(), envelopes.end()); // nlogn
        vector<int> dp(n, 1); // dp[i] is the number of envlopes that i can the outermost 
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < i; ++j)
            {
                if(envelopes[j][0] < envelopes[i][0] && envelopes[j][1] < envelopes[i][1])
                {
                    dp[i] = max(dp[i], 1 + dp[j]);
                }   
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};