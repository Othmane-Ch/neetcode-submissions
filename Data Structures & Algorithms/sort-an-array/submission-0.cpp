class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        priority_queue<int, vector<int>, std::greater<int>> pq;
        for(const auto& num: nums)
        {
            pq.push(num);
        }
        vector<int> result(nums.size(), 0);
        for(int i = 0; i < nums.size(); ++i)
        {
            result[i] = pq.top();
            pq.pop();
        }
        return result;
    }
};