class MedianFinder {
private:
    priority_queue<int> max_pq {};                            
    priority_queue<int, vector<int>, greater<int>> min_pq {};    
public:
    MedianFinder() {}

    // Time: O(log n)
    void addNum(int num) {
        max_pq.push(num);
        min_pq.push(max_pq.top());    
        max_pq.pop();

        if(min_pq.size() > max_pq.size())    
        {
            max_pq.push(min_pq.top());
            min_pq.pop();
        }
    }

    // Time: O(1)
    double findMedian() {
        if(max_pq.size() > min_pq.size())   // odd count
        {
            return static_cast<double>(max_pq.top());
        }
        return (static_cast<double>(max_pq.top()) + min_pq.top()) / 2.0;
    }
};