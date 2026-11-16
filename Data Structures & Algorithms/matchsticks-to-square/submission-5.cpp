#include <numeric>
class Solution {
public:
    bool dfs(int idx, int perim, vector<int>& matchsticks, array<int, 4>& sides)
    {
        if(idx == matchsticks.size())
        {
            return true;
        }

        for(int s = 0; s < 4; ++s)
        {
            if((sides[s] + matchsticks[idx]) * 4 > perim) continue;
            sides[s] += matchsticks[idx];
            if(dfs(idx + 1, perim, matchsticks, sides))
            {
                return true;
            }
            sides[s] -= matchsticks[idx];
        }
        return false;
    }

    bool makesquare(vector<int>& matchsticks) {
        int perim = std::accumulate(matchsticks.begin(), matchsticks.end(), 0);
        sort(matchsticks.rbegin(), matchsticks.rend());
        array<int, 4> sides {}; // 0 -> left side , 1 -> top side, 2 -> right side, 3 -> bottom side
        return dfs(0, perim, matchsticks, sides);
    }
};