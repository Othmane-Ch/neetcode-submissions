class Solution {
public:
    // Time  : O(n)
    // Space : O(1)
    int rob(vector<int>& nums) {
        const int n = nums.size();
        int two = 0, one = 0; 
        for(int i = n - 1; i >= 0; --i)
        {
            int current = max(one, nums[i] + two);
            two = one;
            one = current;
        }
        return one;
    }
};
