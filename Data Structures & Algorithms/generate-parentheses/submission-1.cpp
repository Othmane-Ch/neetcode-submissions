class Solution {
public:


    void dfs(int open, int close, int n,
             string& s, vector<string>& result)
    {
        if(s.size() == 2 * n)
        {
            result.push_back(s);
            return;
        }

        // Add '(' if we still have opening parentheses available
        if(open < n)
        {
            s.push_back('(');
            dfs(open + 1, close, n, s, result);
            s.pop_back();
        }

        // Add ')' only if there is an unmatched '('
        if(close < open)
        {
            s.push_back(')');
            dfs(open, close + 1, n, s, result);
            s.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {

        vector<string> result;
        string s;

        s.reserve(2 * n);

        dfs(0, 0, n, s, result);

        return result;
    }
};