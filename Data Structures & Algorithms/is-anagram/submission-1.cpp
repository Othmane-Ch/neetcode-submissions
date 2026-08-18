class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
        {
            return false;
        }

        std::array<int, 26> freq_s{};
        std::array<int, 26> freq_t{};

        for(const auto& c: s)
        {
            ++freq_s[c - 'a'];
        }

        for(const auto& c: t)
        {
            ++freq_t[c - 'a'];
        }
        return freq_s == freq_t;        
    }
};
