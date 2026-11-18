class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        sort(trips.begin(), trips.end(), [](const auto& a, const auto& b) { return a[1] < b[1];});
        priority_queue<pair<int, int> , vector<pair<int, int>>, greater<pair<int, int>>> min_heap {};
        int current_passengers = 0;
        for(const auto& trip: trips)
        {
            auto num_passengers = trip[0], from = trip[1], to = trip[2];
            while(!min_heap.empty() && min_heap.top().first <= from)
            {
                current_passengers -= min_heap.top().second;
                min_heap.pop();
            }

            if(num_passengers + current_passengers > capacity) return false;
            current_passengers += num_passengers;

            min_heap.push(make_pair(to, num_passengers));
        }
        return true;
    }
};