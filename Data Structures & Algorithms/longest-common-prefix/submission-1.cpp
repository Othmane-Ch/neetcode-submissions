class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = "";
        for(auto i = 0; i < strs.at(0).size(); ++i)
        {
            bool matched = true;
            for(auto j = 1; j < strs.size(); ++j)
            {
                if(i >= strs.at(j).size() || strs.at(0).at(i) != strs.at(j).at(i))
                {
                    matched = false;
                    break;
                }
            }
            if(matched)
            {
                res += strs.at(0).at(i);
            } 
            else 
            {
                break;
            }
        }
        return res;
    }
};