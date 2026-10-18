class Solution {
public:
    void reverseString(vector<char>& s) {
        const int n = s.size();
        const int mid = n/2;
        for(int i = 0; i < mid; ++i)
        {
            std::swap(s[i], s[n - i - 1]);
        }
    }
};