/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int pick = n/2;
        int res = guess(pick);
        while(guess(pick) != 0)
        {
            if(guess(pick) == 1)
            {
                pick += n;
                pick /= 2;
            } else {
                pick /= 2;
            }
        }
        return pick;
    }
};