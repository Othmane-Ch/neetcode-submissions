class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> unique_element(nums.begin(), nums.end());
        const int n = nums.size();
        int max_len = 0;
        for(int num : unique_element) 
        {
            // is num[i] a start of a sequence
            if(!unique_element.contains(num - 1))
            {
                int len = 1;
                while(true)
                {
                    if(unique_element.contains(num + len))
                    {
                        len += 1;
                    }
                    else {
                        break;
                    }
                }
                max_len = max(max_len, len);
            }
        }
        return max_len;

    }
};
