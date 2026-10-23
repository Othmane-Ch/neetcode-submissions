class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> count{};// we can have at most 2 numbers that can appear [n/3] times ==> count will have a maximum of 3 elements whatever n is
        for(const auto& num: nums)
        {
            ++count[num];
            if(count.size() == 3)
            {
                for(auto it = count.begin(); it != count.end();)
                {
                    if(--it->second == 0)
                    {
                        it = count.erase(it);
                    } else{
                        ++it;
                    }
                }
            }
        }
        if(count.empty())
        {
            return {};
        }

        auto it = count.begin();

        int candidate1 = 0;
        int candidate2 = 0;

        candidate1 = it->first;
        ++it;
        candidate2 = candidate1;
        if(it != count.end())
        {
            candidate2 = it->first;
        }
        int count1 = 0;
        int count2 = 0;
        for(const auto& num : nums)
        {
            if(num == candidate1)
            {
                ++count1;
            } else if(num == candidate2 && candidate2 != candidate1)
            {
                ++count2;
            }
        }
        const int threshold = nums.size()/3;
        vector<int> result {};
        if(count1 > threshold)
        {
            result.push_back(candidate1);
        }
        if(candidate2 != candidate1 && count2 > threshold)
        {
            result.push_back(candidate2);
        }
        return result;
    }
};