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
        bool sign = false;
        unsigned int exp = n;
        if(n<0){
            exp = -n;
            sign = true;
        }
        double result = 1.0;
        while (exp) {
            if (exp & 1){
                result *= x;
            }
            printf("exp: %d, result: %lf\n", exp, result);
            exp >>= 1;
            x *= x;
            printf("exp: %d, x: %lf\n\n", exp, x);
        }

        return sign ? 1/result : result;
    }

    int testCase(){
        double x;
        int n;
        x = -2.0;
        n = 5;
        printf("\nx: %lf, n: %d, pow: %lf\n", x, n, myPow(x, n));

        x = 34.00515;
        n = -3;
        //printf("x: %lf, n: %d, expect: 0.00003, pow: %lf\n", x, n, myPow(x, n));

        x = 0.44528;
        n = 0;
        //printf("x: %lf, n: %d, expect: 1.0, pow: %lf\n", x, n, myPow(x, n));

        x = 8.95371;
        n = -1;
        //printf("x: %lf, n: %d, expect: 0.11169, pow: %lf\n", x, n, myPow(x, n));

        x = -4.48392;
        n = 6;
        //printf("x: %lf, n: %d, pow: %lf\n", x, n, myPow(x, n));
        return 0;
    }
};
