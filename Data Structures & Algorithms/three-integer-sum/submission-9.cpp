class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        const int n = nums.size();
        vector<vector<int>> result{};
        int i = 0;
        while (i < n - 2 && nums[i] <= 0)
        {
            if (i > 0 && nums[i] == nums[i-1]) { ++i; continue; }
            
            int l = i+1;
            int r = n-1;
            
            if(nums[i] > 0) { break;}
            while(  l < r )
            {
                if(nums[i] + nums[l] + nums[r] > 0)
                {
                    --r;
                } 
                else if(nums[i] + nums[l] + nums[r] < 0)
                {
                    ++l;
                }   
                else
                {
                    result.push_back({nums[i], nums[l], nums[r]});
                    ++l; --r;
                    while (l < r && nums[l] == nums[l-1]) ++l;   // skip duplicate l
                    while (l < r && nums[r] == nums[r+1]) --r;   // skip duplicate r
                }
            }
            ++i;
        }
        return result;
    }
};
