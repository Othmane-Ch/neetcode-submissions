class Solution {
public:
    int search_helper(vector<int>& nums, int l, int r, int target)
    {
        if(l > r) return -1;
        int mid = l + (r-l+1)/2;
        if(target == nums[mid])
        {
            return mid;
        } else if(target < nums[mid])
        {
            return search_helper(nums, l, mid-1, target);
        } else {
            return search_helper(nums, mid + 1, r, target);
        }
    }
    int search(vector<int>& nums, int target) {
        return search_helper(nums, 0, nums.size()-1, target);
    }
};
