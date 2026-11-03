class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st {};
        for(const auto & op : operations)
        {
            if(op == "C")
            {
                st.pop();
            }
            else if(op == "D")
            {
                int num = st.top();
                st.push(num * 2);
            }
            else if(op == "+")
            {
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.push(num1);
                st.push(num1 + num2);
            } else {
                int num = std::stoi(op);
                st.push(num);
            }
        }
        int sum = 0;
        while(!st.empty())
        {
            int num = st.top();
            st.pop();
            sum += num;
        }
        return sum;
    }
};