class Solution {
public:
    // Time  : O(n)
    // Space : O(1)
    int rob(vector<int>& nums) {
        const int n = nums.size();
        int two = 0, one = nums[n - 1]; 
        for(int i = n - 2; i >= 0; --i)
        {
            int current = max(one, nums[i] + two);
            two = one;
            one = current;
        }
        return one;
    }
};
