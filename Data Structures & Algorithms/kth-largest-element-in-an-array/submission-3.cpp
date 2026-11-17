class Solution {
public:
    // QuickSelect
    // Time  : O(n) on average , O(n^2) worst
    // Space : O(n)
    int findKthLargest(vector<int>& nums, int k) {
        return quickSelect(nums, 0, nums.size() - 1, nums.size() - k);
    }

    int quickSelect(vector<int>& nums, int l, int r, int k)
    {
        int p = l;
        for(int i = l; i < r; ++i)
        {
            if(nums[i] < nums[r])
            {
                swap(nums[i], nums[p]);
                ++p;
            } 
        }

        swap(nums[p], nums[r]);

        if(p > k) // check left side
        {
            return quickSelect(nums, l, p-1, k);
        } else if(p < k) // right side
        {
            return quickSelect(nums, p + 1, r, k);
        } else {
            return nums[p];
        }

    }
};
