/********************************************************************************** 
* 
* Given an array with n objects colored red, white or blue, sort them so that objects of 
* the same color are adjacent, with the colors in the order red, white and blue.
* 
* Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
* 
* Note:
* You are not suppose to use the library's sort function for this problem.
* 
* Follow up:
*  > A rather straight forward solution is a two-pass algorithm using counting sort.
*  > First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array 
*    with total number of 0's, then 1's and followed by 2's.
*  > Could you come up with an one-pass algorithm using only constant space?
*               
**********************************************************************************/

class Solution {
public:

void swap(int*a, int*b)
{   
    int t;
    t=*a;
    *a = *b;
    *b = t;
}
void sortColors(int a[], int n) {
    int zero=0, two=n-1;
    for(int i=0; i<=two; i++ ){
        if (a[i]==0){
            swap(&a[zero], &a[i]);
            zero++;
        }
        if (a[i]==2){
            swap(&a[two], &a[i]);
            two--;
            i--;
        }
    }

}

    int testCase(){
        int n=3;
        vector< vector<int> > matrix = generateMatrix(n, n);
        printVV(matrix);
        return 0;
    }
};
