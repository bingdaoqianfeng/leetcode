/**********************************************************************************
*
* Implement int sqrt(int x).
*
* Compute and return the square root of x.
*
**********************************************************************************/
class Solution {
public:

    //利用二分查找法
    int sqrt(int x) {
        if (x <=0 ) return 0;

        //the sqrt is not greater than x/2+1
        int end = x/2+1;
        int start = 0;
        // binary search
        while ( start <= end ) {
            int mid = start + (end-start)/2;
            long long sq = (long long)mid*(long long)mid;
            if (sq == x ) return mid;
            if (sq < x) {
                start = mid + 1;
            }else {
                end = mid - 1;
            }
        }
        return end;
    }
    int testCase(){
        int n = 7;
        cout << "sqrt(" << n << ") = " << sqrt(n) << endl;
        return 0;
    }
};
