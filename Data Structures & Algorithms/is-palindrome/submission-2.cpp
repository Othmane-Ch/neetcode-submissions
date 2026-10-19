class Solution {
public:
    bool isAlphaNum(char c)
    {
        return (c >= '0' && c <= '9') ||
            (c >= 'A' && c <= 'Z') ||
            (c >= 'a' && c <= 'z');
    }

    bool isPalindrome(string s) {
        const int n = s.size();
        int l = 0;
        int r = n-1;
        while(l<r)
        {
            while(l < r && !isAlphaNum(s[l]))
            {
                ++l;
            }
            while(l < r && !isAlphaNum(s[r]))
            {
                --r;
            }

            if(std::tolower(s[l]) != std::tolower(s[r]))
            {
                return false;
            }
            ++l;
            --r;
        }
        return true; 
    }
};
