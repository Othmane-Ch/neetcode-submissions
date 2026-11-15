class Solution {
public:

    void dfs(int n, vector<int>& permu, unordered_map<int, int>& count,vector<vector<int>>& result)
    {
        if(permu.size() == n)
        {
            result.push_back(permu);
            return;
        }

        for(auto& [k,v] : count)
        {
            if(v > 0)
            {
                --v;
                permu.push_back(k);
                dfs(n, permu, count, result);
                ++v;
                permu.pop_back();
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        unordered_map<int, int> count {};
        for(const auto & num: nums)
        {
            ++count[num];
        }

        vector<vector<int>> result {};
        vector<int> permu {};
        dfs(nums.size(), permu, count, result);
        return result;
    } 
};