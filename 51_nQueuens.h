/********************************************************************************** 
* 
* The n-queens puzzle is the problem of placing n queens on an n×n chessboard 
* such that no two queens attack each other.
* 
* Given an integer n, return all distinct solutions to the n-queens puzzle.
* 
* Each solution contains a distinct board configuration of the n-queens' placement, 
* where 'Q' and '.' both indicate a queen and an empty space respectively.
* 
* For example,
* There exist two distinct solutions to the 4-queens puzzle:
* 
* [
*  [".Q..",  // Solution 1
*   "...Q",
*   "Q...",
*   "..Q."],
* 
*  ["..Q.",  // Solution 2
*   "Q...",
*   "...Q",
*   ".Q.."]
* ]
* 
*               
**********************************************************************************/
class Solution {

public:
    vector< vector<string> > solveNQueens(int n) {
        vector< vector<string> > result;
        return result;
    }
    int testCase(){
        return 0;
    }
    void printVectorVector(vector< vector<string> >& v)
    {
        cout << "[ " <<endl;
        for(int j=0; j<v.size(); j++){
            printVector(v[j]);
        }
        cout << "] " << endl;
    }
    void printVector( vector<string>&  pt)
    {
        cout << "[ ";
        for(int j=0; j<pt.size(); j++){
            cout << pt[j] << "  ";
        }
        cout << "] " << endl;
    }
};
