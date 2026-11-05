class Solution {
public:
    bool is_digit_string(const std::string& s) {
        if (s.empty()) return false;
        for (char c : s) {
            if (c < '0' || c > '9') return false;
        }
        return true;
    }

    string decodeString(string s) {
        stack<string> st {};
        const int n = s.size();
        int i = 0;
        while(i < n)
        {
            if(s[i] == ']')
            {
                string t = "";
                while(!st.empty() && st.top() != "[")
                {
                    t = st.top() + t;
                    st.pop();
                }
                st.pop();
                string k = "";
                while(!st.empty() && is_digit_string(st.top()))
                {
                    k = st.top() + k;
                    st.pop();
                }
                int count = 0;
                auto [ptr, ec] = std::from_chars(k.data(), k.data() + k.size(), count);
                if (ec == std::errc{} && count > 0) {
                    std::string repeated_str;
                    repeated_str.reserve(t.size() * count);
                    for (int j = 0; j < count; ++j) {
                        repeated_str.append(t);
                    }
                    st.push(std::move(repeated_str));
                }
            } else {
                st.push(string(1, s[i]));
            }
            ++i;
        }
        string result = "";
        while(!st.empty())
        {
            result = st.top() + result;
            st.pop();
        }

        return result;
    }
};