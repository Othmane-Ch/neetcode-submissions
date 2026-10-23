class Solution {
public:
    // Recall 
    // Time  : o(n)
    // Space : o(n)
    int longestConsecutive(vector<int>& nums) {
        const int n = nums.size();
        unordered_set<int> unique{};
        for(const auto& num: nums)
        {
            unique.insert(num);
        }
        int max_len = 0;
        for(int i = 0; i < n; ++i)
        {
            if(!unique.contains(nums[i]-1))
            {
                int len = 1;
                while(true)
                {
                    if(unique.contains(nums[i] + len))
                    {
                        ++len;       
                    } else {
                        break;
                    }
                }
                max_len = max(max_len, len);
            }
        }
        return max_len;
    }
};
