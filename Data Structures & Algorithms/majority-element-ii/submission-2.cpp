class Solution {
public:
    // Time complexity : O(n)
    // Space complexioty : O(1) ( hash_map has at most 3 elements but not more than 2 at the end)
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> count{};
        const int threshold = nums.size()/3;
        vector<int> result {};

        for(const auto& num : nums)
        {
            ++count[num];
            if(count.size() > 2)
            {
                for(auto it = count.begin(); it != count.end();)
                {
                    --(it->second);
                    if((it->second) == 0)
                    {
                        it = count.erase(it);
                    }
                    else {
                        ++it;
                    }
                }
            }
        }

        if(count.empty())
        {
            return result;
        }

        auto it = count.begin();
        auto candidate1 = it->first;
        auto candidate2 = it->first;
        ++it;
        if(it != count.end())
        {
            candidate2 = it->first;
        }

        int count1 = 0, count2 = 0;

        for(const auto& num: nums)
        {
            if(num == candidate1)
            {
                ++count1;
            }
            else if(num == candidate2)
            {
                ++count2;
            }
        }


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