class Solution {
public:
    bool validPalindrome(string s) {
        const int n = s.size();
        int l = 0;
        int r = n-1;
        string t = "";

        auto isPal = [&](int i, int j) {
                    while (i < j) {
                        if (s[i] != s[j]) return false;
                        ++i; --j;
                    }
                    return true;
                };

        while(l < r && !s.empty())
        {
            if(s[l] != s[r])
            {
                if(!t.empty()) return false;
                if(s[l+1] != s[r])
                {
                    t += s[r];
                    s.erase(s.begin() + r);
                    --r;
                }
                else if(s[l] != s[r-1])
                {
                    t += s[l];
                    s.erase(s.begin() + l);
                    --r;
                }
                else {
                    return isPal(l + 1, r) || isPal(l, r - 1);
                }
            }
            else {
                ++l;
                --r;
            }
        }
        return t.size() <= 1;
    }
};

