class Solution {
public:

    int rob_aux(vector<int>& nums, int j) {
        const int n = nums.size();
        int two = 0, one = 0; 
        for(int i = n - 1; i >= j; --i)
        {
            int current = max(one, nums[i] + two);
            two = one;
            one = current;
        }
        return one;
    }

    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        int withOutFirst = rob_aux(nums, 1);
        nums.pop_back();
        int withOutLast = rob_aux(nums, 0);
        return  max(withOutFirst, withOutLast);
    }
};
