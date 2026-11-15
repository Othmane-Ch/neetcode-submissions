class Solution {
public:

    const array<string, 10> alphabet = {
        "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
    };



    void dfs(int i, const string& digits, string& s, vector<string>& result)
    {
        if(s.size() == digits.size())
        {
            result.push_back(s);
            return;
        }

        for(char c: alphabet[digits[i] - '0'])
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
