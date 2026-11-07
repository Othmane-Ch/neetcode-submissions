class Solution {
public:
    // Time  : O(n)
    // Space : O(1) with modified input
    int findDuplicate(vector<int>& nums) {
        const int n = nums.size();
        int num = 1;
        for(int i = 0; i < n; ++i)
        {
            while(nums[i] != nums[nums[i]-1])
            {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        for(int i = 1; i < n+1; ++i)
        {
            if(nums[i-1] != i)
            {
                num = nums[i-1];
                break;
            }
        }
        return num;
    }
};