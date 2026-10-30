class Solution {
public:
    // Time  : O(n)
    // Space : O(u), u = number of unique characters in s
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> last_seen;
        int l = 0;
        int max_len = 0;
        for (int r = 0; r < (int)s.size(); ++r)
        {
            if (last_seen.contains(s[r]))
                l = max(l, last_seen[s[r]] + 1);   // jump past the duplicate, never backward
            last_seen[s[r]] = r;                   // always record the newest position
            max_len = max(max_len, r - l + 1);     // r is inclusive here
        }
        return max_len;
    }
};