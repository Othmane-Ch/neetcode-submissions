class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        std::array<int, 61> count {};
        for(const auto& num: nums)
        {
            int idx = num + 30;
            ++count[idx];
        }
        vector<int> result(nums.size(), 1);
        for(auto i = 0; i < nums.size(); ++i)
        {
            int idx = nums[i] + 30;
            for(auto j = 0; j < count.size(); ++j)
            {
                if(count[j] > 0 && j != idx)
                {
                    result.at(i) *= pow((j - 30), count[j]);
                }
            }
            if(count[idx] > 1)
            {  
                result.at(i) *=  pow( nums[i], count[idx] - 1);
            }
        }
        return result;
    }
};
