class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        const int n = cost.size();
        int one = 0, two = 0;
        int i = 2;
        while(i <= n)
        {
            int curr = min(two + cost[i - 2], one + cost[i - 1]);
            two = one;
            one = curr;
            ++i;
        }
        return one;
    }
};
