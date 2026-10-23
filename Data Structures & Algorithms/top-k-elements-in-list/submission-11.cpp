class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        const int n = nums.size();
        unordered_map<int, int> count {};
        for(const auto& num : nums)
        {
            ++count[num];
        }
        // if elements are all the same, that element will be at bucket n+1
        vector<vector<int>> bucket(n+1, vector<int>{});
        for(const auto& [num, fq]: count)
        {
            bucket[fq].push_back(num);
        }
        vector<int> result{}; 
        for(int i = n; i > 0 && result.size() < k; --i)
        {
            while(!bucket[i].empty())
            {
                result.push_back(bucket[i].back());
                bucket[i].pop_back();
            }
        }
        return result;
    }
};
