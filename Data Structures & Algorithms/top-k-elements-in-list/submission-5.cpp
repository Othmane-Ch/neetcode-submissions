class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq {};
        for(const auto& num: nums)
        {
            ++freq[num];
        }
        std::priority_queue<pair<int, int>> pq; 
        for(const auto& [num, fq] : freq)
        {
            pq.push(make_pair(fq, num));
        }
        vector<int> res{};
        while(k>0)
        {
            res.push_back(pq.top().second);
            pq.pop();
            --k;
        }
        return res;
    }
};
