class Solution {
public:
    // Time  : O(n)
    // Space : O(1)
    int numDecodings(string s) {
        const int n = s.size();
        int one = 1;
        int two = 1;
        for(int i = n - 1; i >= 0; --i)
        {
            if(s[i] == '0')
            {
                two = one;
                one = 0;
            } else {
                auto tmp = one;
                if(i < n - 1 && ((s[i] == '1' && ( s[i + 1] >= '0' && s[i + 1] <= '9')) || (s[i] == '2' && ( s[i + 1] >= '0' && s[i + 1] <= '6'))))
                {
                    one += two;   
                }
                two = tmp;
            }
        }
        return one;
    }
};
