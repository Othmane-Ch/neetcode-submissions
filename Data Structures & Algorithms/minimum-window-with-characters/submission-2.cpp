class Solution {
public:
    // Time  : O(n + m)   — n = |s|, m = |t| (average case; hash map ops are O(1) on average)
    // Space : O(u) extra — u = distinct chars in t
    string minWindow(string s, string t) {
        const int ns = s.size();
        const int nt = t.size();
        if(nt > ns)
        {
            return "";
        }
        unordered_map<char, int> count_t {}, count_window {};
        for(const auto& c: t)
        {
            ++count_t[c];
        }

        int missing = nt;   // how many chars of t (counting repeats) the window still lacks

        int l = 0;
        int r = 0;
        int best_start = 0;
        int best_len = INT_MAX;   // INT_MAX means "no valid window found yet"

        while(r < ns)
        {
            if(l == r && !count_t.contains(s[r]))
            {
                ++l;
                ++r;
                continue;
            }
            if(!count_t.contains(s[r]))
            {
                ++r;
            } else {
                // Adding s[r] only helps if we still needed more of this char
                if(count_window[s[r]] < count_t[s[r]])
                {
                    --missing;
                }
                ++count_window[s[r]];

                while(missing == 0)   // window is valid: O(1) check
                {
                    if(r - l + 1 < best_len)
                    {
                        best_start = l;
                        best_len = r - l + 1;
                    }
                    if(count_t.contains(s[l]))
                    {
                        --count_window[s[l]];
                        // Removing s[l] only hurts if we now have fewer than needed
                        if(count_window[s[l]] < count_t[s[l]])
                        {
                            ++missing;
                        }
                    }
                    ++l;
                }

                ++r;
            }
        }

        if (best_len == INT_MAX)
        {
            return "";
        }

        return s.substr(best_start, best_len);
    }
};