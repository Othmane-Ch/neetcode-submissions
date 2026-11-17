class Solution {
public:
    // Time  : O(n*log(k))
    // Space : O(log(k))
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> min_pq {};
        for(const auto& num : nums)
        {
            if(min_pq.size() >= k)
            {
                if(num > min_pq.top())
                {
                    min_pq.pop();
                    min_pq.push(num);
                }
            } else {
                min_pq.push(num);
            }
        }
        return min_pq.top();
    }
};
