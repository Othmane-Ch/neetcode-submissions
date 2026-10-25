class Solution {
public:
    int maxArea(vector<int>& heights) {
        const int n = heights.size();
        int l = 0;
        int r = n-1;
        int maxAr = 0;
        while(l<r)
        {
            int width = r-l;
            maxAr = max(maxAr, width * min(heights[r], heights[l]));
            if(heights[l] < heights[r])
            {
                ++l;
            }else {
                --r;
            }
        }
        return maxAr;
    }
};
