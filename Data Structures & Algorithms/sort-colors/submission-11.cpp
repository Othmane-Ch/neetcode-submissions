class Solution {
public:
    void sortColors(vector<int>& nums) {
        // Three pointer
        int l = 0;
        int r = nums.size() - 1;
        int i = 0;
        while(i <= r)
        {
            if(nums[i] == 2)
            {
                if(nums[r] != 2)
                {
                    std::swap(nums[i], nums[r]);
                }
                --r;
            } 
            else if(nums[i] == 0)
            {
                if(nums[l] != 0)
                {
                    std::swap(nums[i], nums[l]);
                }
                ++l;
                ++i;
            } 
            else {
                ++i;
            }
            
        }
    }
};