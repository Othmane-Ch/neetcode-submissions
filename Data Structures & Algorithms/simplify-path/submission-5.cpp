class Solution {
public:
    string simplifyPath(string path) {
        vector<string> st;
        int n = path.size();
        int i = 0;
        while (i < n)
        {
            if(path[i] == '/')
            {
                ++i;
            } else {
                string s = "";
                while(path[i] != '/' && i < n)
                {
                    s += path[i];
                    ++i;
                }
                if(s == "..")
                {
                    if(!st.empty())
                    {
                        st.pop_back();
                    }
                } else if(s == ".")
                {
                    continue;
                } else {
                    st.push_back(s);
                }
            }
        }
        string result = "";
        for(const auto& s: st)
        {
            result += "/";
            result += s;
        }
        
        return result.empty() ? "/" : result;
    }
};