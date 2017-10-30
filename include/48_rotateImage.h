/**********************************************************************************
*
* You are given an n x n 2D matrix representing an image.
* Rotate the image by 90 degrees (clockwise).
* Follow up:
* Could you do this in-place?
*
**********************************************************************************/
class Solution {
public:
    void rotate(vector< vector<int> >& matrix) {
        int n = matrix.size();
        if(n<=1) return;

        for(int row=0; row < (n+1)/2; row++){
            for(int col = row; col < n-1-row; col++){
                int temp = matrix[row][col];

                matrix[row][col] = matrix[n-1-col][row];

                matrix[n-1-col][row] = matrix[n-1-row][n-1-col];

                matrix[n-1-row][n-1-col] = matrix[col][n-1-row];

                matrix[col][n - 1 -row] = temp;
                printf("row: %d, col: %d\n", row, col);
                printMatrix(matrix);
            }
        }
        return;
    }
    int testCase(){
        int n = 5;
        vector< vector<int> > matrix;
        for (int i=1; i<=n; i++) {
            vector<int> v;
            for(int j=1; j<=n; j++){
                v.push_back( (i-1)*n + j );
            }
            matrix.push_back(v);
        }
        printMatrix(matrix);

        rotate(matrix);
        //printMatrix(matrix);
        return 0;
    }
    void printMatrix(vector< vector<int> > &matrix)
    {
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j< matrix[i].size(); j++) {
                printf("%3d ", matrix[i][j]) ;
            }
            cout << endl;
        }
        cout << endl;
    }
};
