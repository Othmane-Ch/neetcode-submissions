class Solution {
public:
    // Time  : O(n²)
    // Space : O(1)
    string longestPalindrome(string s) {
        const int n = s.size();
        int max_l = 0;
        int max_r = 0;

        for(int i = 0; i < n; ++i)
        {
            int l = i;
            int r = i;
            while(l >= 0 && r < n)
            {
                if(s[l] != s[r]) break;
                if(max_r - max_l < r - l)
                {
                    max_l = l;
                    max_r = r;
                }
                ++r;
                --l;
            }
            l = i;
            r = i + 1;
            while(l >= 0 && r < n)
            {
                if(s[l] != s[r]) break;
                if(max_r - max_l < r - l)
                {
                    max_l = l;
                    max_r = r;
                }
                ++r;
                --l;
            }
        }
        return s.substr(max_l, max_r - max_l + 1);
    }
};
