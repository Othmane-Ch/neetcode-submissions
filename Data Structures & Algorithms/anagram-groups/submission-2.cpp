class Solution {
   public:
   
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<std::string, vector<string>> mapp;

        for(const auto& str: strs)
        {
            std::array<int, 26> count {};
            for(const auto& c : str)
            {
                ++count[c - 'a'];
            }

            std::string key = "";
            for (int i = 0; i < 26; ++i) {
                key += std::to_string(count[i]) + ','; 
            }

            mapp[key].push_back(str);            
        }
        vector<vector<string>> result;

        for(const auto& [_, vec] : mapp)
        {
            result.push_back(vec);
        }
        return result;
    }
};
