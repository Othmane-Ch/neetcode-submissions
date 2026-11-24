class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        for(int i = 0; i < k + 1; ++i)
        {
            vector<int> tmpDist = dist;
            for(int j = 0; j < flights.size(); ++j)
            {
                int s = flights[j][0], d = flights[j][1], p = flights[j][2];
                if(tmpDist[s] == INT_MAX) continue;
                if(tmpDist[s] + p < dist[d])
                {
                    dist[d] = tmpDist[s] + p;
                }
            }
        }
        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};
