/********************************************************************************** 
* 
* Implement pow(x, n).
* 
**********************************************************************************/
class Solution {
public:
/*
 *   Basically, most people think this is very easy as below:
 *
 *      double result = 1.0;
 *      for (int i=0; i<n; i++){
 *           result *=x;
 *      }
 *
 *   However,
 *
 *     1) We need think about the `n` is negtive number.
 *
 *     2) We need more wisely deal with the following cases:
 *
 *         pow(1, MAX_INT);
 *         pow(-1,BIG_INT);
 *         pow(2, BIG_INT);
 *
 *        To deal with such kind case, we can use x = x*x to reduce the `n` more quickly
 *
 *        so, if `n` is an even number, we can `x = x*x`, and `n = n>>1;`
 *            if `n` is an odd number, we can just `result *= x;`
 *
 */
    double myPow(double x, int n) {
        double result = 1.0;
        int sign = 1.0;
        int exp = n;
        if(n == 0){
            return result;
        }
        if(x < 0){
            if(n%2 == 1)
                sign = -1.0;
            x *= sign;
        }
        if(n < 0){//如果指数是负数，那么2^(-3)的结果是1/8,即1/(2^3).
            exp = -n;
        }

        for(int i = 0; i < exp; i++){
            if(INT_MAX - result <x)
                return INT_MAX;
            result *= x;
        }

        if(n<0){
            result = 1/result;
        }

        return result*sign;
    }
    int testCase(){
        double x = 2.0;
        int n = 3;
        printf("x: %lf, n: %d, pow: %lf\n", x, n, myPow(x, n));

        x = 34.00515;
        n = -3;
        printf("x: %lf, n: %d, pow: %lf\n", x, n, myPow(x, n));

        x = -4.48392;
        n = 6;
        printf("x: %lf, n: %d, pow: %lf\n", x, n, myPow(x, n));
        return 0;
    }
};
