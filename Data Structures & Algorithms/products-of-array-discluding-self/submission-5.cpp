class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        const int n = nums.size();
        vector<int> prefix_product(n+1, 1);
        vector<int> suffix_product(n+1, 1);

        for(int i = 0; i < n; ++i)
        {
            prefix_product[i+1] = prefix_product[i] * nums[i];
        }

        for(int i = 1; i < n; ++i)
        {
            suffix_product[n-i] = suffix_product[n-i+1] * nums[n-i];
        }

        vector<int> result(n, 0);
        for(int i = 1; i < n+1; ++i)
        {
            result[i-1] = prefix_product[i-1] * suffix_product[i];
        }
        return result;
    }
};
