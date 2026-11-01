class Solution {
public:
    int mySqrt(int x) {
        if(x == 0)
        {
            return 0;
        }
        
        int low = 1;
        int high = x;
        long long mid {};
        while(low <= high)
        {
            mid = (long long)low + (high - low)/2;
            if(mid * mid == x)
            {
                return mid;
            } else if(mid * mid < x)
            {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return high;
    }
};