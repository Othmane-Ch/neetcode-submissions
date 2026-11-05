class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        int max_area = 0;
        const int n = heights.size();
        stack<pair<int, int>> st {};
        int i = 0;
        while(i < n)
        {
            if(st.empty())
            {
                st.push(make_pair(i, 0));
            } else {
                int l = 0;
                while(!st.empty() && heights[st.top().first] > heights[i])
                {
                    max_area = max(max_area, heights[st.top().first] * (i -  st.top().first + st.top().second));
                    l += st.top().second + 1;
                    st.pop();
                }
                st.push(make_pair(i, l));
            }
            ++i;
        }
        return max_area;
    }
};
