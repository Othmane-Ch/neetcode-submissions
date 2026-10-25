class Solution {
public:
    // Time  : O(n)
    // Space : O(1)
    void rotate(vector<int>& nums, int k) {
        if(k == 0)
        {
            return;
        }
        k %= nums.size();
        std::reverse(nums.begin(), nums.end());
        std::reverse(nums.begin(), nums.begin() + k);
        std::reverse(nums.begin() + k, nums.end());
    }
};