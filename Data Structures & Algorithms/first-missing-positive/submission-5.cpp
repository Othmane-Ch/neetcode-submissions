class Solution {
public:
    // result belongs to [1, n+1] and could be proven with contradiction (suppose it doesn't and build up the logic)
    int firstMissingPositive(vector<int>& nums) {
        const int n = nums.size();
        for(int i = 0; i < n; ++i)
        {
            while(1 <= nums[i] && nums[i] <= n && nums[i] != nums[nums[i] - 1])
            {
                std::swap(nums[i], nums[nums[i] - 1]);
            }
        }

        for(int i = 0; i < n; ++i)
        {
            if(nums[i] != i+1)
            {
                return i+1;
            }
        }

        return n+1;
    }
};