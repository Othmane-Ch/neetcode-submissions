class Solution {
public:
    //  Time  : O(nlog(k))
    //  Space : O(n)
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int l = 0;
        int r = 0;

        vector<int> result{};
        priority_queue<pair<int, int>> max_heap {};
        while(r < nums.size())
        {
            while(r - l < k)
            {
                max_heap.push(make_pair(nums[r], r));
                ++r;
            }

            while(!max_heap.empty())
            {
                auto [num, i] = max_heap.top();
                if( i >= l && i < r)
                {
                    result.push_back(num);
                    break;
                } else {
                    max_heap.pop();
                }
            }
            ++l;
        }
        return result;
    }
};
