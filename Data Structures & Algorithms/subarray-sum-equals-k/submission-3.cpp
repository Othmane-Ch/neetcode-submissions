class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        const int n = nums.size();
        vector<int> preSum(n+1, 0);
        for(int i = 0; i < n; ++i)
        {
            preSum[i+1] = preSum[i] + nums[i];
        }
        
        unordered_map<int, int> count {{0,1}};
        
        int result = 0;
        int i = 1;
        while(i <= n)
        {
            if(count.contains(preSum[i] - k))
            {
                result += count[preSum[i] - k];
            }
            ++count[preSum[i]];
            ++i;
        }
        return result;
    }
};