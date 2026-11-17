class Solution {
public:
    // Time  : O(n log(n))
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> min_pq {};
        
        for(int i = 0; i < points.size(); ++i)
        {
            double distance = sqrt(points[i][0]*points[i][0] + points[i][1]*points[i][1]);
            min_pq.push(make_pair(distance, i));
        }
        vector<vector<int>> result(k, vector<int>(2, 0));
        while(k > 0)
        {
            auto [_ , i] = min_pq.top(); min_pq.pop();
            result[k-1][0] = points[i][0];
            result[k-1][1] = points[i][1];
            --k;
        }
        return result;
    }
};
