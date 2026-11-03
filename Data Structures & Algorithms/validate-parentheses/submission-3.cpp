class Solution {
public:
    bool isValid(string s) {
        const int n = s.size();
        if(n % 2 != 0 || n == 0) return false;
        int i = 1;
        stack<char> st {};
        st.push(s[0]);
        while(i < n)
        {
            if(s[i] == ')' && !st.empty() && st.top() == '(')
            {
                st.pop();
            } else if(s[i] == '}' && !st.empty() && st.top() == '{')
            {
                st.pop();
            } else if(s[i] == ']' && !st.empty() && st.top() == '[')
            {
                st.pop();
            } else {
                st.push(s[i]);
            }
            ++i;
        }
        return st.empty();        
    }
};
