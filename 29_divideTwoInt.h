/**********************************************************************************
*
* Divide two integers without using multiplication, division and mod operator.
*
* If it is overflow, return MAX_INT.
*
**********************************************************************************/
class Solution {

public:
/*
*最直观的方法是，用被除数逐个的减去除数，直到被除数小于0。这样做会超时。
*那么如果每次不仅仅减去1个除数，计算速度就会增加，但是题目不能使用乘法，
*因此不能减去k*除数，我们可以对除数进行左移位操作，这样每次相当于减去2^k个除数，如何确定k呢，只要使 (2^k)*除数 <=  当前被除数 <(2^(k+1))*除数.
*/
    int divide(int dividend, int divisor) {
        int sign = (float)dividend / divisor > 0 ? 1 : -1;
        unsigned int dvd = dividend > 0 ? dividend : -dividend;
        unsigned int dvs = divisor > 0 ? divisor : -divisor;

        unsigned int bit_num[32];
        unsigned int i=0;
        long long d = dvs;
        bit_num[i] = d;
        while( d <= dvd ){
            bit_num[++i] = d = d << 1;
        }
        i--;

        unsigned int result = 0;
        while(dvd >= dvs){
            if (dvd >= bit_num[i]){
                dvd -= bit_num[i];
                result += (1<<i);
            }else{
                i--;
            }
        }

        //becasue need to return `int`, so we need to check it is overflowed or not.
        if ( result > INT_MAX && sign > 0 ) {
            return INT_MAX;
        }
        return (int)result * sign;
    }
    int testCase(){
        cout << "0/2=" << divide(0, 2) << endl;
        cout << "10/2=" << divide(10, 2) << endl;
    cout << "10/3=" << divide(10, 3) << endl;
    cout << "10/5=" << divide(10, 5) << endl;
    cout << "10/7=" << divide(10, 7) << endl;
    cout << "10/10=" << divide(10, 10) << endl;
    cout << "10/11=" << divide(10, 11) << endl;
    cout << "-1/1=" << divide(1, -1) << endl;
    cout << "1/-1=" << divide(1, -1) << endl;
    cout << "-1/-1=" << divide(-1, -1) << endl;
    cout << "2147483647/1=" << divide(2147483647, 1) << endl;
    cout << "-2147483647/1=" << divide(-2147483647, 1) << endl;
    cout << "2147483647/-1=" << divide(2147483647, -1) << endl;
    cout << "-2147483647/-1=" << divide(-2147483647, -1) << endl;
    cout << "2147483647/2=" << divide(2147483647, 2) << endl;
    cout << "2147483647/10=" << divide(2147483647, 10) << endl;
    cout << "-2147483648/1=" << divide(-2147483648, 1) << endl;
    cout << "-2147483648/-1=" << divide(-2147483648, -1) << endl;
        return 0;
    }
};
