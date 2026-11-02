class Solution {
public:
    // Time  :O(n) (all element can be the same)
    // Space : O(1) 
    bool search(vector<int>& nums, int target) {
        const int n = nums.size();
        int l = 0;
        int r = n - 1;
        while(l <= r)
        {
            int mid = l + (r - l)/2;
            if(nums[l] == nums[r])
            {
                if(nums[l] == target)
                {
                    return true;
                }
                --r;
                ++l;
            }
            else if(nums[l] < nums[r])
            {
                if(nums[mid] == target)
                {
                    return true;
                } 
                else if(target > nums[mid])
                {
                    l = mid + 1;
                } else{
                    r = mid - 1;
                }
            }
            
            else if(nums[l] <= nums[mid])
            {
                if( nums[l] <= target  && target <= nums[mid])
                {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            } 

            else
            {    
                if( target <= nums[r]  && target >= nums[mid])
                {
                    l = mid;
                } else {
                    r = mid - 1;
                }
            } 
        }
        return false;
        
    }
};
