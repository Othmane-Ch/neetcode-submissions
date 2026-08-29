#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<bool>> seen(n, vector<bool>(n, false));
        priority_queue<tuple<int, int, int>,
                       vector<tuple<int, int, int>>,
                       greater<tuple<int, int, int>>> pq;

        pq.push({grid[0][0], 0, 0});
        seen[0][0] = true;

        int dirs[5] = {1, 0, -1, 0, 1};

        while (!pq.empty()) {
            auto [time, r, c] = pq.top();
            pq.pop();

            if (r == n - 1 && c == n - 1) return time;

            for (int k = 0; k < 4; ++k) {
                int nr = r + dirs[k], nc = c + dirs[k + 1];
                if (nr < 0 || nc < 0 || nr >= n || nc >= n) continue;
                if (seen[nr][nc]) continue;

                seen[nr][nc] = true;
                pq.push({max(time, grid[nr][nc]), nr, nc});
            }
        }

        return -1;
    }
};