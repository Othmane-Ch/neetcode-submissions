class Solution {
public:
    int countSubstrings(string s) {
        const int n = s.size();
        int res = 0;
        auto expand = [&](int l, int r)
        {
            while(l >= 0 && r < n && s[l] == s[r])
            {
                ++res;
                ++r;
                --l;
            }
        };

        for(int i = 0; i < n; ++i)
        {
            expand(i, i); // Odd palindromes
            expand(i, i + 1); // even palindromes
        }
        return res;
    }
};
