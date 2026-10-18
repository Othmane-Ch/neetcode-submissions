class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> pos{};

        for(const auto& num: nums)
        {
            if(num > 0)
            {
                pos.insert(num);
            }
        }
        
        if(pos.empty())
        {
            return 1;
        }

        const auto [min_val, max_val] = std::ranges::minmax(pos);
        if(min_val > 1)
        {
            return 1;
        }
        int result = max_val + 1;
        for(int i = min_val + 1; i < nums.size() + 1; ++i)
        {
            if(!pos.contains(i))
            {
                result = i;
                break;
            }
        }
        return result;
    }
};