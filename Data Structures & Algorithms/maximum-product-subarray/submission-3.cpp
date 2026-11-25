class Solution {
public:
    // Time  : O(n)
    // Space : O(n)
    int maxProduct(vector<int>& nums) {
        const int n = nums.size();
        vector<int> dp_max(n, 1);
        vector<int> dp_min(n, 1);
        for(int i = 0; i < n; ++i)
        {
            if( i > 0)
            {
                dp_max[i] = max(nums[i], max(dp_max[i - 1] * nums[i], dp_min[i - 1] * nums[i]));
                dp_min[i] = min(nums[i], min(dp_max[i - 1] * nums[i], dp_min[i - 1] * nums[i]));
            } else {
                dp_max[0] = nums[0];
                dp_min[0] = nums[0];
            }
        }

        int max_product = *max_element(dp_max.begin(), dp_max.end());
        return max_product;
    }
};
