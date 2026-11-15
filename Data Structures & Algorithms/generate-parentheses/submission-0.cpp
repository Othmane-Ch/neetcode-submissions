class Solution {
public:

    void dfs(int& n, std::string& s, unordered_map<char, int>& count, vector<string>& result)
    {
        if(s.size() == 2*n)
        {
            result.push_back(s);
            return;
        }
        if(count['('] <= count[')'])
        {
            if(count['('])
            {
                --count['('];
                s.push_back('(');
                dfs(n, s, count, result);
                s.pop_back();
                ++count['('];
            }
            if(count[')'] )
            {
                --count[')'];
                s.push_back(')');
                dfs(n, s, count, result);
                s.pop_back();
                ++count[')'];
            }
        }

    }

    vector<string> generateParenthesis(int n) {
        unordered_map<char, int> count {};
        count['('] = n;
        count[')'] = n;
        vector<string> result {};
        string s = "";
        dfs(n, s, count, result);
        return result;
    }
};
