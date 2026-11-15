class Solution {
public:

    bool dfs(int idx, int sum, int side, int perim, vector<bool>& seen, const vector<int>& matchsticks)
    {
        if (side == 4)
            return true;
        if (sum * 4 == perim)
            return dfs(0, 0, side + 1, perim, seen, matchsticks);
        for(int i = idx; i < matchsticks.size(); ++i)
        {
            if((sum + matchsticks[i]) * 4 > perim || seen[i]) continue;
            seen[i] = true;
            if (dfs(i + 1, sum + matchsticks[i], side, perim, seen, matchsticks))
                return true;
            seen[i] = false;
        }
        return false;
    }

   bool makesquare(vector<int>& matchsticks) {
        int perim = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        vector<bool> seen(matchsticks.size(), false);
        return dfs(0, 0, 0, perim, seen, matchsticks);
    }
};