class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st {};
        for(const auto& c : tokens)
        {
            if(c == "+")
            {
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                st.push(num2 + num1);
            } else if(c == "*")
            {
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                st.push(num2 * num1);
            } else if(c == "-")
            {
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                st.push(num2 - num1);
            } else if(c == "/")
            {
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                st.push(num2/num1);
            } else {
                int num = stoi(c);
                st.push(num);
            }
        }
        return st.top();
    }
};
