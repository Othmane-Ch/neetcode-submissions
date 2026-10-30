class Solution {
public:
    // Time  : O(n)
    // Space : O(u) u unique letters at most 26
    int characterReplacement(string s, int k) {
        unordered_map<char, int> count {};
        int max_len = 0;
        int l = 0;
        int max_freq = 0;
        for(int r = 0; r < s.size(); ++r)
        {
            ++count[s[r]];
            max_freq = max(max_freq, count[s[r]]);
            if((r - l + 1 - max_freq) >  k)
            {
                --count[s[l]];
                ++l;
            }
            max_len = max(max_len, r-l+1);
        }
        return max_len;
    }
};
