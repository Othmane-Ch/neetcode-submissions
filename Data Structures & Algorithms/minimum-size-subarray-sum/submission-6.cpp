class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        const int n = nums.size();
        int l = 0;
        int r = 1;
        int min_len = n+1;
        int sum = nums[l];
        while(l < r )
        {
            if(sum < target && r < n)
            {
                sum += nums[r];
                ++r;
                continue;
            }
            if(sum >= target)
            {
                min_len = min(min_len, r-l);
                
            }
            sum -= nums[l];  
            ++l;
        }

        return min_len == n+1 ? 0 : min_len;
        
    }
};