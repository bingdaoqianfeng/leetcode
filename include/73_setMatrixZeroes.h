/********************************************************************************** 
* 
* Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
* 
* click to show follow up.
* 
* Follow up:
* 
* Did you use extra space?
* A straight forward solution using O(mn) space is probably a bad idea.
* A simple improvement uses O(m + n) space, but still not the best solution.
* Could you devise a constant space solution?
* 
*               
**********************************************************************************/
class Solution {
public:
/*
据说这题是CareerCup上的原题，我还没有刷CareerCup，所以不知道啦，不过这题也不算难，虽然我也是看了网上的解法照着写的，但是下次遇到绝对想的起来。这道题中说的空间复杂度为O(mn)的解法自不用多说，直接新建一个和matrix等大小的矩阵，然后一行一行的扫，只要有0，就将新建的矩阵的对应行全赋0，行扫完再扫列，然后把更新完的矩阵赋给matrix即可，这个算法的空间复杂度太高。将其优化到O(m+n)的方法是，用一个长度为m的一维数组记录各行中是否有0，用一个长度为n的一维数组记录各列中是否有0，最后直接更新matrix数组即可。这道题的要求是用O(1)的空间，那么我们就不能新建数组，我们考虑就用原数组的第一行第一列来记录各行各列是否有0.

- 先扫描第一行第一列，如果有0，则将各自的flag设置为true
- 然后扫描除去第一行第一列的整个数组，如果有0，则将对应的第一行和第一列的数字赋0
- 再次遍历除去第一行第一列的整个数组，如果对应的第一行和第一列的数字有一个为0，则将当前值赋0
- 最后根据第一行第一列的flag来更新第一行第一列
*/
	void setZeroes(vector<vector<int>>& matrix) {
		int m = matrix.length;  
        int n = matrix[0].length;  
        int i, j;  
          
        //先标记第一行和第一列是否有0  
        boolean firstRow = false, firstCol = false;  
        for (j = 0; j < n; j++) {  
            if (0 == matrix[0][j]) {  
                firstRow = true;  
                break;  
            }  
        }  
        for (i = 0; i < m; i++) {  
            if (0 == matrix[i][0]) {  
                firstCol = true;  
                break;  
            }  
        }  
           
        //从第二行第二列还是遍历，如果遇到0，则把它所在行和列的第一个值设为0     
        for (i = 1; i < m; i++) {  
            for (j = 1; j < n; j++) {  
                if (0 == matrix[i][j]) {  
                    matrix[i][0] = 0;  
                    matrix[0][j] = 0;  
                }  
            }  
        }  
          
        //把第一列的0所在行都设为0，把第一行的0所在列都设为0  
        for (i = 1; i < m; i++) {  
            if (0 == matrix[i][0]) {  
                for (j = 1; j < n; j++) {  
                    matrix[i][j] = 0;  
                }  
            }  
        }  
        for (j = 1; j < n; j++) {  
            if (0 == matrix[0][j]) {  
                for (i = 1; i < m; i++) {  
                    matrix[i][j] = 0;  
                }  
            }  
        }  
          
        //根据标记决定第一行和第一列是否全设为0  
        if (firstRow) {  
            for (j = 0; j < n; j++) {  
                matrix[0][j] = 0;  
            }  
        }  
        if (firstCol) {  
            for (i = 0; i < m; i++) {  
                matrix[i][0] = 0;  
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
