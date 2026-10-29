class Solution {
public:
    int trap(vector<int>& height) {
        const int n = height.size();
        int totalWater = 0;
        int i = 0;
        while(i < n)
        {
            if(height[i] == 0){
                ++i;
                continue;
            }
            int base = 0;
            int j = i+1;
            while(j < n && height[i] > height[j])
            {
                base += height[j];
                ++j;
            }
            if(j == n) { break;}
            int water = height[i] * (j - i - 1) - base;
            totalWater += water;
            i = j;
        }
        // Right to left
        i = n-1;
        while(i > 0)
        {
            if(height[i] == 0){
                --i;
                continue;
            }
            int base = 0;
            int j = i-1;
            while(j >= 0 && height[j] <= height[i])
            {
                base += height[j];
                --j;
            }
            if(j < 0) { break;}
            int water = (height[i] * (i-j-1)) - base;
            if( water > 0) {
                totalWater += water;
            }
            i = j;
        }
        return totalWater;
    }
};
