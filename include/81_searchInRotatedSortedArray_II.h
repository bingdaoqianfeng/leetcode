/**********************************************************************************
*
* Follow up for "Search in Rotated Sorted Array":
* What if duplicates are allowed?
*
* Would this affect the run-time complexity? How and why?
*
* Write a function to determine if a given target is in the array.
*
**********************************************************************************/

// Using the same idea "Search in Rotated Sorted Array"
// but need be very careful about the following cases:
//   [3,3,3,4,5,6,3,3]
//   [3,3,3,3,1,3]
// After split, you don't know which part is rotated and which part is not.
// So, you have to skip the ducplication
//   [3,3,3,4,5,6,3,3]
//          ^       ^
//   [3,3,3,3,1,3]
//            ^ ^

class Solution {
public:
    int testCase(){
        int n=3;
        vector< vector<int> > matrix = generateMatrix(n, n);
        printVV(matrix);
        return 0;
    }
};
