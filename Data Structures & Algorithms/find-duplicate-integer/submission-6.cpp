class Solution {
public:
    // Time  : O(n)
    // Space : O(1)  extra space
    int findDuplicate(vector<int>& nums) {
        const int n = nums.size();
        int slow = 0;
        int fast = 0;

        while(true)
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if(slow == fast){
                fast = 0;
                break;
            }
        }

        while(true)
        {
            slow = nums[slow];
            fast = nums[fast];
            if(slow == fast){
                return slow;
            }
        }
    }
};