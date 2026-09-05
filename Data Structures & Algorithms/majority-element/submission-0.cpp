class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> count {};
        const int cst = nums.size() / 2;
        for(const auto& num: nums)
        {
            ++count[num];
            if(count[num] > cst)
            {
                return num;
            }
        }
        
    }
};