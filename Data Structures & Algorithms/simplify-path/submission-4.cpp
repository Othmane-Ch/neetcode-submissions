class Solution {
public:
    string simplifyPath(string path) {
        string st = "";
        int n = path.size();
        int i = 0;
        while (i < n)
        {
            if (st.empty())
            {
                st.push_back(path[i]);
            }
            else if (path[i] == '/')
            {
                while (!st.empty() && st.back() == '/')
                    st.pop_back();
                st.push_back('/');
            }
            else if (path[i] == '.' && st.back() == '/')
            {
                int j = i;
                while (i < n && path[i] == '.')
                    ++i;
                int dots = i - j;
                bool wholeName = (i == n || path[i] == '/');

                if (wholeName && dots == 2)
                {
                    int slashes = 0;
                    while (!st.empty())
                    {
                        if (st.back() == '/') ++slashes;
                        st.pop_back();
                        if (slashes == 2) break;
                    }
                    if (st.empty()) st.push_back('/');
                }
                else if (!(wholeName && dots == 1))
                {
                    st.append(dots, '.');
                }
                --i;
            }
            else
            {
                st.push_back(path[i]);
            }
            ++i;
        }
        while (st.size() > 1 && st.back() == '/')
            st.pop_back();
        if (st.empty()) st.push_back('/');
        return st;
    }
};