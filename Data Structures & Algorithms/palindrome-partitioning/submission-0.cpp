class Solution {

    bool isPalandrome(const string& word)
    {
        int l = 0;
        int r = word.size()-1;
        while(l < r)
        {
            if(word[l] != word[r])
            {
                return false;
            }
            ++l;
            --r;
        }
        return true;
    }

    void dfs(int idx, const string& s, vector<string>& subPart, vector<vector<string>>& result)
    {
        if(idx == s.size())
        {
            result.push_back(subPart);
            return;
        }

        for (int len = 1; len + idx <= s.size(); ++len) 
        {
            string t = s.substr(idx, len);
            if(!isPalandrome(t)) continue;
            subPart.push_back(t);
            dfs(len + idx, s, subPart, result);            
            subPart.pop_back();
        }
    }

public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result {};
        vector<string> subPart {};
        dfs(0, s, subPart, result);    
        return result;
    }
};
