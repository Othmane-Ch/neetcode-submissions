class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        int r = 1;
        while (r < nums.size())
        {
            if(nums[r] <= nums[i])
            {
                ++r; 
            } else {
                ++i;
                swap(nums[i], nums[r]);
            }
            
        }
        return i+1;
        
    }
};