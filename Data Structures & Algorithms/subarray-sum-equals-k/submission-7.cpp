class Solution {
public:
    // Recall
    // Time  : o(n)
    // Space : o(n)
    int subarraySum(vector<int>& nums, int k) {
        const int n = nums.size();
        std::vector<int> prefix(n + 1, 0);
        for(int i = 0; i < n; ++i)
        {
            prefix[i+1] = prefix[i] + nums[i];
        }

        unordered_map<int, int> count{};
        int res {};
        for(int i = 0; i < n+1; ++i)
        {
            if(count.contains(prefix[i] - k))
            {
                res += count[prefix[i] - k];
            }
            ++count[prefix[i]];
        }
        return res;        
    }
};