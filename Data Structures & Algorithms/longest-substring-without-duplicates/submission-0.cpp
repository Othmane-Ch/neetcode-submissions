class Solution {
public:
    // Time  : O(n)
    // Space : O(u) u number of unique elements in s
    int lengthOfLongestSubstring(string s) {
        const int n = s.size();
        int l = 0;
        int max_len = 0;
        unordered_set<char> seen {};
        int r = 0;
        while (l < n && r < n)
        {
            while(r < n && !seen.contains(s[r]))
            {
                seen.insert(s[r]); 
                ++r;
            }
            max_len = max(max_len, (int) seen.size());
            seen.erase(s[l]);
            ++l;
        }
        return max_len;
    }
};
