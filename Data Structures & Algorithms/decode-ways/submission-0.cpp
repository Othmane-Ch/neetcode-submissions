class Solution {
public:
    int numDecodings(string s) {
        const int n = s.size();
        vector<int> dp(n + 1);
        dp[n] = 1;
        dp[n - 1] = s[n - 1] == '0' ? 0 : 1;
        for(int i = n - 2; i >= 0; --i)
        {
            if(s[i] == '0')
            {
                dp[i] = 0;
                continue;
            }
            
            int one = dp[i+1]; 

            int two = 0;
            if((s[i] == '1' && s[i + 1]  >= '0' &&  s[i + 1] <= '9') || (s[i] == '2' && s[i + 1] >='0' &&  s[i + 1] <= '6'))
            {
                two = dp[i + 2];
            }
            dp[i] = one + two;
        }
        return dp[0];
    }
};
