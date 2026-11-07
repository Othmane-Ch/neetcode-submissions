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

        for(int i = 0; i < n; ++i)
        {
            if(nums[i] != i+1)
            {
                num = nums[i];
                break;
            }
        }
        return num;
    }
};
