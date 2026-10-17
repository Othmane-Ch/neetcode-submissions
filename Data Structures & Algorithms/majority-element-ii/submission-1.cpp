class Solution {
public:
    // Time complexity : O(n)
    // Space complexioty : O(n)
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> count{};
        const int threshold = nums.size()/3;
        vector<int> result {};
        for(const auto& num : nums)
        {
            ++count[num];
        }

        for(const auto& [k, v] : count)
        {
            if(v > threshold)
            {
                result.push_back(k);
            }
        }
        return result;
    }
};