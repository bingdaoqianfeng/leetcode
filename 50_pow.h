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
		if(n == 0){
			return result;
		}
		if(x < 0){
			sign = -1.0;
			x *= sign;
		}
		
		for(int i = 0; i < n; i++){
			if(INT_MAX - result <x)
				return INT_MAX;
			result *= x;	
		}

		return result;
    }
	int testCase(){
		double x = 2.0;
		int n = 3;
		printf("x: %lf, n: %d, pow: %lf\n", x, n, myPow(x, n));
		return 0;
	}
};
