class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> mmap{};
        for(int i = 0; i < numbers.size(); ++i)
        {
            mmap[numbers[i]] = i; 
        }
        int i = 0;
        int j = 0;
        while(i < numbers.size())
        {
            j = mmap[target - numbers[i]];
            if(numbers[i] + numbers[j] == target)
            {
                break;
            }
            ++i;
        }
        return {i+1, j+1};
        
    }
};
