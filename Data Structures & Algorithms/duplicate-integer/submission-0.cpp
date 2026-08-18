class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_set<int> my_set(nums.begin(), nums.end());
        return  my_set.size() < nums.size();
    }
};