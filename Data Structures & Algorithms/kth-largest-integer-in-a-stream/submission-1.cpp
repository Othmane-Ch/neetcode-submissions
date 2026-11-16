class KthLargest {
private :
    int i = 0;
    int k = 0;
    priority_queue<int, vector<int>, greater<int>> min_pq {};
public:
    KthLargest(int k, vector<int>& nums) : k(k), min_pq(nums.begin(), nums.end()) {
        if(min_pq.size() > k)
        {
            while(min_pq.size() > k)
            {
                min_pq.pop();
            }
        }
    }
    
    int add(int val) {
        if(min_pq.size() < k)
        {
            min_pq.push(val);
        } else
        {
            if(val > min_pq.top())
            {
                min_pq.pop();
                min_pq.push(val);
            }
        }
        return min_pq.top();
    }
};
