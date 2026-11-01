class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        int mid = 0;
        while(l <= r)
        {
            mid = l + (r - l)/2;
            if(target < nums[mid])
            {
                r = mid - 1;
            } else if(target > nums[mid])
            {
                l = mid + 1;
            } else {
                return mid;
            }
        }
        return l;
    }
};