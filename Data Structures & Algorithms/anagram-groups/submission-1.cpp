class Solution {
   public:
    struct ArrayHash {
        size_t operator()(const std::array<int, 26>& arr) const {
            size_t h = 0;
            for (int i : arr) {
                h ^= std::hash<int>{}(i) + 0x9e3779b9 + (h << 6) + (h >> 2);
            }
            return h;
        }
    };

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<std::array<int, 26>, vector<string>, ArrayHash> mapp;

        for(const auto& str: strs)
        {
            std::array<int, 26> count {};
            for(const auto& c : str)
            {
                ++count[c - 'a'];
            }
            mapp[count].push_back(str);            
        }
        vector<vector<string>> result;

        for(const auto& [_, vec] : mapp)
        {
            result.push_back(vec);
        }
        return result;
    }
};
