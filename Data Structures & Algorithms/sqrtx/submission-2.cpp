class Solution {
public:
    int mySqrt(int x) {
        if(x == 1)
        {
            return 1;
        }
        if(x == 0)
        {
            return 0;
        }

        long long y = 2;
        while(y*y <= x)
        {
            ++y;
        }
        return y-1;
    }
};