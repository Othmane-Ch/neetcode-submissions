class Solution {
public:
    // Time  : O(n)
    // Space : O(n)
    bool isValid(string s) {
        const int n = s.size();
        if(n % 2 != 0 || n == 0) return false;
        int i = 0;
        stack<char> st {};

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
