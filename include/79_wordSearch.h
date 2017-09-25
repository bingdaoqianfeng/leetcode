/********************************************************************************** 
* 
* Given a 2D board and a word, find if the word exists in the grid.
* 
* The word can be constructed from letters of sequentially adjacent cell, 
* where "adjacent" cells are those horizontally or vertically neighboring. 
* The same letter cell may not be used more than once.
* 
* For example,
* Given board = 
* 
* [
*   ["ABCE"],
*   ["SFCS"],
*   ["ADEE"]
* ]
* 
* word = "ABCCED", -> returns true,
* word = "SEE", -> returns true,
* word = "ABCB", -> returns false.
* 
*               
**********************************************************************************/

class Solution {
public:
//深度优先搜索
//Recursive backtracking algorithm
bool exist(vector<vector<char> > &board, string word, int idx, int row, int col, vector< vector<int> > &mask) {
    int i = row;
    int j = col;
    if (board[i][j] == word[idx] && mask[i][j]==0 ) {
        mask[i][j]=1; //mark the current char is matched
        if (idx+1 == word.size()) return true;
        //checking the next char in `word` through the right, left, up, down four directions in the `board`.
        idx++;
        if (( i+1<board.size()    && exist(board, word, idx, i+1, j, mask) ) ||
            ( i>0                 && exist(board, word, idx, i-1, j, mask) ) ||
            ( j+1<board[i].size() && exist(board, word, idx, i, j+1, mask) ) ||
            ( j>0                 && exist(board, word, idx, i, j-1, mask) ) )
        {    
             return true;
        }
        mask[i][j]=0; //cannot find any successful solution, clear the mark. (backtracking)
    }

    return false;
}

bool exist(vector<vector<char> > &board, string word) {
    if (board.size()<=0 || word.size()<=0) return false;
    int row = board.size();
    int col = board[0].size();
    //using a mask to mark which char has been selected.
    //do not use vector<bool>, it has big performance issue, could cause Time Limit Error
    vector< vector<int> > mask(row, vector<int>(col, 0));

    for(int i=0; i<board.size(); i++) {
        for(int j=0; j<board[i].size(); j++){
            if ( board[i][j]==word[0] ){
                vector< vector<int> > m = mask;
                if( exist(board, word, 0, i, j, m) ){
                    return true;
                }
            }
        }
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
