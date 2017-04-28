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
class Solution {

public:
    bool isValidSudoku(vector< vector<char> >& board) {
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
                printf("%c ", str[j]);
                board[i][j] = str[j];
            }
        }

        //print
        for(int i = 0; i<board.size(); i++){
            for(int j=0; j<9; j++){
                printf("%c ", board[i][j]);;
            }
            printf("\n");;
        }
        return 0;
    }
};
