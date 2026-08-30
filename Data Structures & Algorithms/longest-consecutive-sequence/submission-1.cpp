class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> values(nums.begin(), nums.end());
        int best = 0;

        for (int x : values) {
            if (values.contains(x - 1)) {
                continue;
            }

            int current = x;
            int length = 1;

            while (values.contains(current + 1)) {
                ++current;
                ++length;
            }

            best = max(best, length);
        }

        return best;
    }
};