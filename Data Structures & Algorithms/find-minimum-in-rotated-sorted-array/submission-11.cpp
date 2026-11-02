class Solution {
public:
    // Time  : O(log(n))
    // Space : O(1) extra space
    int findMin(vector<int> &nums) {
        int l = 0;
        int r = nums.size()-1;
        while(true)
        {
            if (nums[l] <= nums[r]) return nums[l]; 
            int mid = l + (r - l)/2;
            if(nums[mid] > nums[r])
            {
                l = mid+1;
            } else {
                r = mid;
            }
        }
        
    }
};
