class Solution {
public:
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

        for(const auto& candidate : candidates)
        {
            bool isTownJudge = true;
            int townJudge = candidate;
            for(const auto & [num, s] : adjacents)
            {
                if(!s.contains(candidate))
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