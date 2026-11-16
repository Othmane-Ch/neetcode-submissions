class Solution {
public:
    // Time  : O(n*log(n) + O(n)  ( heapify is O(n) )
    // Space : O(n)
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> max_pq(stones.begin(), stones.end());
        while(true)
        {
            if(max_pq.empty()) return 0;
            if(max_pq.size() == 1) return max_pq.top();

            int max_1 = max_pq.top(); max_pq.pop();
            
            if(max_1 > max_pq.top())
            {
                int max_2 = max_pq.top(); max_pq.pop();
                max_pq.push(max_1 - max_2);
            } else {
                max_pq.pop();
            }
        }
    }
};
