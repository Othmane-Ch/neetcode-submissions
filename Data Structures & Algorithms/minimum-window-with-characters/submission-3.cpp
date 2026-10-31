class Solution {
public:
    // Time  : O(u * n + m)
    // Space : O(u) u are the unique elements in  t
    bool is_subset(const std::unordered_map<char, int>& sub_map, const std::unordered_map<char, int>& main_map) {
        // 1. A subset cannot be larger than the main set
        if (sub_map.size() > main_map.size()) {
            return false;
        }

        // 2. Verify all key-value pairs exist in the main map
        for (const auto& [key, val] : sub_map) {
            auto it = main_map.find(key);
            
            // If key doesn't exist, or value doesn't match, it's not a subset
            if (it == main_map.end() || it->second < val) {
                return false;
            }
        }

        return true;
    }
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

        int l = 0;
        int r = 0;
        int best_start = 0;
        int best_len = INT_MAX;
 
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
                ++count_window[s[r]];
                while(is_subset(count_t, count_window))
                {
                    if(r - l + 1 < best_len)
                    {
                        best_start = l;
                        best_len = r - l + 1;
                    }
                    if(count_window.contains(s[l]) && count_window[s[l]] > 0)
                    {
                        --count_window[s[l]];
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
