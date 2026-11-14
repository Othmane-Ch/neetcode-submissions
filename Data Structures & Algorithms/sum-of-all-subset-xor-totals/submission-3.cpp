class Solution {
public:
    // Time  : O(n)
    // Space : O(1)
    int subsetXORSum(vector<int>& nums) {
        const int n = nums.size();
        int res = 0;
        for(const auto& num : nums)
        {
            res |= num;
        }
        return res << n-1;
    }
};