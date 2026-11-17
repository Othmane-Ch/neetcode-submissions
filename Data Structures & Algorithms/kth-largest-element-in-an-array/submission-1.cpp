class Solution {
public:
    // Time  : O(n)
    // Space : O(1) extra space // counting sort
    int findKthLargest(vector<int>& nums, int k) {
        array<int, 2001> count {};
        for(const auto& num : nums)
        {
            ++count[num + 1000];
        }

        for(int i = count.size() - 1; i >= 0; --i)
        {
            while(count[i] != 0)
            {
                --(count[i]);
                --k;
                if(k == 0)
                {
                    return i - 1000;
                }
            }
        }
    }
};
