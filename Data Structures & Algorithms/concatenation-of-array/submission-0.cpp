class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        auto n = nums.size();
        vector<int> ans(2*n, 0);
        auto i = 0;
        while(i < 2*n)
        {
            int num = i < n ? nums.at(i) : nums.at(i-n);
            ans.at(i) = num;
            ++i;
        }
        return ans;
    }
};