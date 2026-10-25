class Solution {
public:
    // Time  : O(n·k)
    // Space : O(1)
    void rotate(vector<int>& nums, int k) {
        if(k == 0)
        {
            return;
        }
        const int n = nums.size();
        k %= n;
        int r = n-1;
        while( r > n-k-1)
        {
            int j = n-1;
            while(j > 0)
            {
                swap(nums[j], nums[j-1]);
                --j;
            }
            --r;
        }
    }
};