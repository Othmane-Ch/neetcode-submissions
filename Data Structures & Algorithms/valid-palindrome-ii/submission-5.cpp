class Solution {
public:
    // Time  : o(n)
    // Space : o(1)

    bool validPalindrome(string s) {
        const int n = s.size();


        auto isPal = [&](int i, int j) {
                    while (i < j) {
                        if (s[i] != s[j]) return false;
                        ++i; --j;
                    }
                    return true;
                };

        int l = 0;
        int r = n-1;
        while(l < r)
        {
            if (s[l] != s[r])
            {
                return isPal(l+1, r) || isPal(l, r-1);
            }
            ++l;
            --r;
        }
        return true;
    }
};

