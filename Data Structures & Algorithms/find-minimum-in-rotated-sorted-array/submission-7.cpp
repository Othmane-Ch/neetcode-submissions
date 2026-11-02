class Solution {
public:
    int findMin(vector<int> &nums) {
        if(nums.size() == 1)
        {
            return nums[0];
        } else if(nums.size() == 2)
        {
            return nums[0] < nums[1] ? nums[0] : nums[1];
        } 

        int l = 0;
        int r = nums.size()-1;
        while(true)
        {
            if (nums[l] <= nums[r]) return nums[l]; 
            int mid = l + (r - l)/2;
            if((mid > 0 && nums[mid] > nums[r] && nums[mid-1] < nums[mid]) || (nums[mid] > nums[r]))
            {
                l = mid+1;
            } else if(mid > 0  && nums[mid] < nums[l] && nums[mid-1] < nums[mid]) 
            {
                r = mid-1;
            } else {
                return nums[mid];
            }
        }
        
    }
};
