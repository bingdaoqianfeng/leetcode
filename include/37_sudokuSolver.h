/**********************************************************************************
*
* Write a program to solve a Sudoku puzzle by filling the empty cells.
*
* Empty cells are indicated by the character '.'.
*
* You may assume that there will be only one unique solution.
*
* A sudoku puzzle...
*
* ...and its solution numbers marked in red.
*
**********************************************************************************/
/*
三个循环，各判断行、列、小九宫格是否合法，为了节省时间，可以用bitmap来代表这个数字是否出现，bitmap可以用数组，只有0到9的数字为index，false和true为值，出现过值为true， 关于vector里面装bool类型，在<<Effective STL>> 这本书里有说明，最好不要在vector装bool类型。由于有规律，三个在不同循环判断的可以写在一个里面。
*/

const int n = 9;
bool rows[n][n] = {false};   //each row record each row of board.
bool cols[n][n]= {false};    //each row record each col of board.
bool subbox[n][n] = {false}; //each row record each subbox of board.

class Solution {
public:
    bool recursiveSudoku(vector< vector<char> >& board, int row, int col){
        if(row >= n)
            return true;

        if(col >= n){
            return recursiveSudoku(board, row+1, 0);
        }

        if(board[row][col] == '.'){
            for(int i=0; i<n; i++){
                int realrow, realcol;
                realrow = (row/3)*3 + col/3;
                realcol = i;
                if(rows[row][i] || cols[col][i] || subbox[realrow][realcol]){
                    //printf("realrow: %d, realcol: %d, row: %d, col: %d, val: %d\n", realrow, realcol, row, col, i+1);
                    continue;
                }
                rows[row][i] = cols[col][i] = subbox[realrow][realcol] = true;
                board[row][col] = i + '1';
                if(recursiveSudoku(board, row, col+1)){
                    return true;
                }
                rows[row][i] = cols[col][i] = subbox[realrow][realcol] = false;
                board[row][col] = '.';
            }
            return false;
        }
        else{
            return recursiveSudoku(board, row, col+1);
        }
    }

    void solveSudoku(vector< vector<char> >& board) {
        isValidSudoku(board);
        recursiveSudoku(board, 0, 0);
    }

    int testCase(){
        vector< vector<char> > board(9);
        vector<string> s(9);
        s[0] = "53..7....";
        s[1] = "6..195...";
        s[2] = ".98....6.";
        s[3] = "8...6...3";
        s[4] = "4..8.3..1";
        s[5] = "7...2...6";
        s[6] = ".6....28.";
        s[7] = "...419..5";
        s[8] = "....8..79";
        for(int i = 0; i<9; i++){
            string str = s[i];
            board[i].resize(9);
            for(int j=0; j<9; j++){
                //printf("%c ", str[j]);
                board[i][j] = str[j];
            }
        }
        printboard(board);
        printf("is sudu: %d\n", isValidSudoku(board));
        solveSudoku(board);
        printf("result:\n");
        printboard(board);
        printf("is sudu: %d\n", isValidSudoku(board));
        return 0;
    }

    bool isValidSudoku(vector< vector<char> >& board) {
        memset(rows, false, sizeof(rows));
        memset(cols, false, sizeof(cols));
        memset(subbox, false, sizeof(subbox));
        for(int i = 0; i<n; i++){
            for(int j=0; j<n; j++){
                char val;
                //each row
                val = board[i][j];
                //if(!isdigit(val))
                if(val == '.')
                    continue;

                int idx = val - '0' - 1;
                int realrow, realcol;
                realrow = (i/3)*3 + j/3;
                realcol = idx;
                if(rows[i][idx] || cols[j][idx] || subbox[realrow][realcol]){
                    //printf("realrow: %d, realcol: %d, i: %d, j: %d\n", realrow, realcol, j, i);
                    return false;
                }
                rows[i][idx] = cols[j][idx] = subbox[realrow][realcol] = true;
            }
        }
        return true;
    }

    void printboard(vector< vector<char> > board){
        for(int i = 0; i<board.size(); i++){
            for(int j=0; j<9; j++){
                printf("%c ", board[i][j]);;
            }
            printf("\n");;
        }
    }
};
