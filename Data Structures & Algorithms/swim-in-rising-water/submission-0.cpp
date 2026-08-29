#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> times;
        for (auto& row : grid) {
            for (int x : row) times.push_back(x);
        }
        sort(times.begin(), times.end());

        int dirs[5] = {1, 0, -1, 0, 1};

        for (int t : times) {
            if (grid[0][0] > t) continue;

            vector<vector<bool>> seen(n, vector<bool>(n, false));
            queue<pair<int, int>> q;
            q.push({0, 0});
            seen[0][0] = true;

            while (!q.empty()) {
                auto [r, c] = q.front();
                q.pop();

                if (r == n - 1 && c == n - 1) return t;

                for (int k = 0; k < 4; ++k) {
                    int nr = r + dirs[k], nc = c + dirs[k + 1];
                    if (nr < 0 || nc < 0 || nr >= n || nc >= n) continue;
                    if (seen[nr][nc] || grid[nr][nc] > t) continue;
                    seen[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }

        return -1;
    }
};