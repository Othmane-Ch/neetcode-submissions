class Solution {
public:
    // Time  : O((n + k) log(k))
    // Space : O(k)
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double, int>> max_pq {}; // size k
        
        for(int i = 0; i < points.size(); ++i)
        {
            double distance = sqrt(points[i][0]*points[i][0] + points[i][1]*points[i][1]);
            if(max_pq.size() < k)
            {
                max_pq.push(make_pair(distance, i));
            } 
            else if(distance < max_pq.top().first)
            {
                max_pq.pop();
                max_pq.push(make_pair(distance, i));
            }
        }
        vector<vector<int>> result(k, vector<int>(2, 0));
        while(k > 0)
        {
            auto [ _ , i] = max_pq.top(); max_pq.pop();
            result[k-1][0] = points[i][0];
            result[k-1][1] = points[i][1];
            --k;
        }
        return result;
    }
};
