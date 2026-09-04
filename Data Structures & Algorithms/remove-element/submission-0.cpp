#include <iostream>
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        auto newEnd = std::remove(nums.begin(), nums.end(), val);
        return newEnd - nums.begin();
    }
};