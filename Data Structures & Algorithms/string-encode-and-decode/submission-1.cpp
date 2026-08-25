#include <iostream>
#include <string>
class Solution {
public:
    // ["hello", "world"] <=> "5#hello5#world"
    string encode(vector<string>& strs) {
        string res{};
        for(const auto& str: strs)
        {
            res += to_string(str.size()) + "#" + str;
            
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> result {};
        int i = 0;
        while(i < s.size())
        {
            string s_size = "";
            while(s.at(i) != '#')
            {
                s_size += s.at(i);
                ++i;
            }
            int size = s_size.empty() ? 0 : std::stoi(s_size);
            i += 1;
            result.push_back(s.substr(i, size));
            i += size;
        }
        return result;
    }
};
