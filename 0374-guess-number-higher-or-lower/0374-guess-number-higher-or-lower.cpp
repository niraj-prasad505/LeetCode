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
        int start=1;
        int end=n;

        while(start <= end){
            int guess_number= start + (end - start) / 2;
            int val = guess(guess_number);

            if (val==0){
                return  guess_number;
            }else if(val==-1){
                end= guess_number-1;
            }else{
                start= guess_number+1;
            }
        }
        return -1;
        
    }
};