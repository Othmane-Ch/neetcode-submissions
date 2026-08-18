class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::vector<int> result{};
        std::unordered_map<int, int> idx_map {};
        for(int i = 0; i < nums.size(); i++)
        {
            if(idx_map.contains(nums[i]))
            {
                result.push_back(idx_map.at(nums.at(i)));
                result.push_back(i);
                break;
            }
            else {
                int diff = target - nums.at(i);
                idx_map.insert({diff, i});
            }
        }
        return result;
    }
};
