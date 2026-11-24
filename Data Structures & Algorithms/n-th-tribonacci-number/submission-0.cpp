class Solution {
public:
    int tribonacci(int n) {
        if(n == 0) return 0;
        if(n == 1 || n == 2) return 1;
        int zero = 0, one = 1, two = 1;
        int i = 3;
        while(i <= n)
        {
            int curr = zero + one + two;
            zero = one;
            one = two;
            two = curr;
            ++i;
        }
        return two;
        
    }
};