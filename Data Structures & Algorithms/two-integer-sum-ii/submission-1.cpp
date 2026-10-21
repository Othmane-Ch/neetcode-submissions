class Solution {
public:
    // Time  : o(n)
    // Space : o(1)
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0;
        int r = numbers.size()-1;
        while(numbers[l] + numbers[r] != target && l < r)
        {
            if(numbers[l] + numbers[r] > target)
            {
                --r;
            } else if(numbers[l] + numbers[r] < target)
            {
                ++l;
            }
        }
        return {l+1, r+1};
    }
};
