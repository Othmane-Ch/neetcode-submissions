class Solution {
public:
    // Time  : O(log(n) + log(n)) = O(log(n))
    // Space : O(1) 

    int search(vector<int>& nums, int target) {
        const int n = nums.size();
        int l = 0;
        int r = n - 1;
        while(l < r)
        {
            int mid = l + (r - l)/2;
            if(nums[mid] == target)
            {
                return mid;
            } 
            else if(nums[l] <= nums[mid])
            {
                if( nums[l] <= target  && target <= nums[mid])
                {
                    r = mid;
                    break;
                }
                l = mid + 1;
            } else if(nums[mid] <= nums[r]) 
            {    
                if( target <= nums[r]  && target >= nums[mid])
                {
                    l = mid;
                    break;
                }
                r = mid - 1;
            } 
        }
        while(l <= r)
        {
            int mid = l + (r - l)/2;
            if(nums[mid] == target)
            {
                return mid;
            } 
            else if(target > nums[mid])
            {
                l = mid + 1;
            } else{
                r = mid - 1;
            }
        }
        return -1;
        
    }
};
