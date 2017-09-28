/**********************************************************************************
*
* Reverse digits of an integer.
*
* Example1: x =  123, return  321
* Example2: x = -123, return -321
*
*
* Have you thought about this?
*
* Here are some good questions to ask before coding. Bonus points for you if you have already thought through this!
*
* > If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.
*
* > Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer,
*   then the reverse of 1000000003 overflows. How should you handle such cases?
*
* > Throw an exception? Good, but what if throwing an exception is not an option?
*   You would then have to re-design the function (ie, add an extra parameter).
*
*
**********************************************************************************/
class Solution {
public:
//#define INT_MAX     2147483647
//#define INT_MIN     (-INT_MAX - 1)
    int reverse(int x) {
        int retval = 0;
        int temp;
        
        while(x !=0){
            temp = x%10;
            //printf("temp=%d, retval=%d \n", temp, retval);
            if(retval > INT_MAX/10 || retval < INT_MIN/10){
                return 0;
            }
            retval = retval*10 + temp;
            x = x/10;
            //printf("x=%d, retval=%d \n", x, retval);
        }
        return retval;
    }
    int testCase(){
        printf("-219 mod 10 -> %d, 219 mod 10 -> %d \n", -219%10, 219%10);
        printf("219 --> %d \n", reverse(219));
        printf("-219 --> %d \n", reverse(-219));
        printf("10 --> %d \n", reverse(10));
        printf("1534236469 --> %d \n", reverse(1534236469));
        return 0;
    }
};
