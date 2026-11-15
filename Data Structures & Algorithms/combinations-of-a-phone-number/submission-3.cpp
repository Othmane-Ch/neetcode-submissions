class Solution {
public:

    unordered_map<char, string> alphabet = {
        {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
        {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
    };

    void dfs(int i, const string& digits, string& s, vector<string>& result)
    {
        if(s.size() == digits.size())
        {
            result.push_back(s);
            return;
        }

        for(char c: alphabet[digits[i]])
        {
            s.push_back(c);
            dfs(i + 1, digits, s, result);
            s.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        vector<string> result {};
        string s {};
        dfs(0, digits, s, result);
        return result;
    }
};
