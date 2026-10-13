class Solution {
public:
    void sortColors(vector<int>& nums) {
        // couting Sort
        std::array<int, 3> count{};
        for(const auto& num : nums)
        {
            ++count[num];
        }
        int j = 0;
        for(int i = 0; i < count.size(); ++i)
        {
            while(count[i] > 0)
            {
                nums[j] = i;
                ++j;
                --count[i];
            }
        }
    }
};