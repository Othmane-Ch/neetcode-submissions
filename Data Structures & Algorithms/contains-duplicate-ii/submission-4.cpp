class Solution {
public:
    // Time  : O(n)
    // Space : O(u) // u number of unique elements in nums
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> count {};
        for(int i = 0; i < nums.size(); ++i)
        {
            if(count.contains(nums[i]) && abs(i - count[nums[i]]) <= k)
            {
                return true;
            } 
            count[nums[i]] = i;
        }
        return false;
    }
};