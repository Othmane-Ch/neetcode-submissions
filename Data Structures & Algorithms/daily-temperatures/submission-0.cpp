class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        const int n = temperatures.size();
        vector<int> result(n, 0);
        stack<pair<int, int>> st;
        st.push(make_pair(temperatures[0], 0));
        for(int i = 1; i < n; ++i)
        {
            while(!st.empty() && temperatures[i] > st.top().first)
            {
                result[st.top().second] =  i - st.top().second;
                st.pop();
            }
            st.push(make_pair(temperatures[i], i));
        }
        return result;
    }
};
