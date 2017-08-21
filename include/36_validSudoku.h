/**********************************************************************************
*
* Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.
*
* The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
*
* A partially filled sudoku which is valid.
*
* Note:
* > A valid Sudoku board (partially filled) is not necessarily solvable.
*   Only the filled cells need to be validated.
*
**********************************************************************************/
/*
三个循环，各判断行、列、小九宫格是否合法，为了节省时间，可以用bitmap来代表这个数字是否出现，bitmap可以用数组，只有0到9的数字为index，false和true为值，出现过值为true， 关于vector里面装bool类型，在<<Effective STL>> 这本书里有说明，最好不要在vector装bool类型。由于有规律，三个在不同循环判断的可以写在一个里面。
*/

class Solution {
public:
    bool isValidSudoku(vector< vector<char> >& board) {
		const int n = 9;
		bool rows[n][n] = {false};	 //each row record each row of board.		
		bool cols[n][n]= {false};    //each row record each col of board.
		bool subbox[n][n] = {false}; //each row record each subbox of board.
		for(int i = 0; i<n; i++){
			for(int j=0; j<n; j++){
				char val;
				//each row
				val = board[i][j];
				if(val != '.'){
					int row = val - '0' - 1;
					if(rows[i][row] == false){
						rows[i][row] = true;
					}
					else{
						printf("error: row: %d, row: %d, col: %d \n", row, i, j);
						return false;
					}
				}
				//each col
				val = board[j][i];
				if(val != '.'){
					int col = val - '0' - 1;
					if(cols[col][i] == false)
						cols[col][i] = true;
					else{
						printf("col: %d, row: %d, col: %d \n", col, j, i);
						return false;
					}
				}
				//each subbox
				val = board[i][j];
				if(val != '.'){
					int realrow, realcol;
					realrow = (i/3)*3 + j/3;
					realcol = val - '0' - 1;
					if(subbox[realrow][realcol] == false)
						subbox[realrow][realcol] = true;
					else{
						printf("realrow: %d, realcol: %d, i: %d, j: %d\n", realrow, realcol, j, i);
						return false;
					}
				}
			}
		}		
        return true;
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

		printf("is valaid sudoku: %d \n",isValidSudoku(board));
        return 0;
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
