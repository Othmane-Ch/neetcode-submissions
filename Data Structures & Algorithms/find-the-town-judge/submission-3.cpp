class Solution {
public:
    // Time  : O(n)
    // Space : O(n)
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int, unordered_set<int>> adjacents {};
        for(const auto& v : trust)
        {
            adjacents[v[0]].insert(v[1]);
        }
        vector<int> candidates {};


        for(int i = 1; i <= n; ++i)
        {
            auto it = adjacents.find(i);
            if(it == adjacents.end())
            {
                candidates.push_back(i);
            }
        }

        if (candidates.size() == 1)
        {
            bool isTownJudge = true;
            int townJudge = candidates[0];
            for(const auto & [num, s] : adjacents)
            {
                if(!s.contains(townJudge))
                {
                    isTownJudge = false;
                    break;
                }
            }
            if(isTownJudge) return townJudge;
        }


        return -1;
    }
};