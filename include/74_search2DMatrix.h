
/********************************************************************************** 
* 
* Write an efficient algorithm that searches for a value in an m x n matrix. 
* This matrix has the following properties:
* 
* Integers in each row are sorted from left to right.
* The first integer of each row is greater than the last integer of the previous row.
* 
* For example,
* 
* Consider the following matrix:
* 
* [
*   [1,   3,  5,  7],
*   [10, 11, 16, 20],
*   [23, 30, 34, 50]
* ]
* 
* Given target = 3, return true.
*               
**********************************************************************************/

class Solution {
public:
/*
思路：

问题隐含的一个信息就是：每一列也从上到下递增。

方法1：

将二维数组按行展开的话，就是一个排序的一维数组，因此通过一维数组的二分查找很容易得到答案。

方法2：

鉴于数组的规律性，选取数组查找范围的右上角数字，如果与查找的数字相等， 则返回true，如果比查找的数字大，则将该数字所在列从查找范围剔除，如果比查找数字小，则将该数字所在行从查找范围中剔除。

方法3：

先通过二分查找元素所在的行，再在所在行通过二分查找元素。
*/
	bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int rows=matrix.size();
        int cols=matrix[0].size();
        int left=0,right=(rows*cols-1);
        int mid,r,c,val;
        while(left<=right){
            mid=left+((right-left)>>1);
            r=mid/cols;
            c=mid%cols;
            if(matrix[r][c]==target)
                return true;
            if(matrix[r][c]<target)
                left=mid+1;
            else
                right=mid-1;
        }
        return false;
    }

    int testCase(){
        int n=3;
        vector< vector<int> > matrix = generateMatrix(n, n);
        printVV(matrix);
        return 0;
    }
};
