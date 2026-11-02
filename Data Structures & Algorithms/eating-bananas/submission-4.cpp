class Solution {
public:
    // Time  : O(nlog(m))
    // Space : O(1) extra space
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        int res = r;

        while (l <= r) {
            int k = l + (r - l) / 2;
            long long time {};
            for(const auto& pile: piles)
            {
                time += (long long) (pile + k - 1) / k;
            }
            if(time <= h)
            {
                res = k;
                r = k-1;
            } else if(time > h)
            {
                l = k+1;
            }
        }
        return res;
    }
};