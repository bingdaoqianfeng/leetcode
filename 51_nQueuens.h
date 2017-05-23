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
    void updateChessboard(vector< vector<int> >& chessboard, int n, int row, int col){
        for(int i=0; i<n; i++) {
            chessboard[row][i] = 1;
            chessboard[i][col] = 1;
        }

        int lefttoprow = row - 1;
        int lefttopcol = col - 1;
        while(lefttoprow >= 0 && lefttopcol >= 0){
            chessboard[lefttoprow][lefttopcol] = 1;
            lefttoprow--;
            lefttopcol--;
        }

        int righttoprow = row - 1;
        int righttopcol = col + 1;
        while(righttoprow >= 0 && righttopcol < n){
            chessboard[righttoprow][righttopcol] = 1;
            righttoprow--;
            righttopcol++;
        }

        int leftbottomrow = row + 1;
        int leftbottomcol = col - 1;
        while(leftbottomrow < n && leftbottomcol >= 0){
            chessboard[leftbottomrow][leftbottomcol] = 1;
            leftbottomrow++;
            leftbottomcol--;
        }

        int rightbottomrow = row + 1;
        int rightbottomcol = col + 1;
        while(rightbottomrow < n && rightbottomcol < n){
            chessboard[rightbottomrow][rightbottomcol] = 1;
            rightbottomrow++;
            rightbottomcol++;
        }
    }

	int getPosition(vector< vector<int> >& chessboard, int n, int row, int col){
			for(int j=col+1; j<n; j++){
				if(chessboard[row][j] != 1){
					return j;
				}
			}
			return col;
	}
	
	recurSolveNQueens(vector< vector<string> >& result, int n, int row, int col,
					 vector< vector<int> > chessboard, vector<string> onesolution){
		if(row == n-1){
			string s(n, '.');
			s[col] = 'Q';
			onesolution.push_back(s);
			result.push_back(onesolution);
		}
		int col = 0;
		for(int i=0; i<n; i++){
        	vector< vector<int> > tempboard = chessboard;
			updateChessboard(tempboard, n, row, i);
			int ret;
			do{
				ret = getPosition(tempboard, n, row+1, col);
				ret = col;
				vector<string> temp = onesolution;
				string s(n, '.');
				s[col] = 'Q';
				temp.push_back(s);
				recurSolveNQueens(result, n, row+1, )
			}while(ret != col);
		}
	}

    vector< vector<string> > solveNQueens(int n) {
        vector< vector<string> > result;
		vector<string> onesolution;
        vector< vector<int> > chessboard(n, vector<int>(n, 0));

		recurSolveNQueens(result, n, 0, 0, chessboard, onesolution)

        for(int i=0; i<n; i++){
            vector< vector<int> > chessboard(n, vector<int>(n, 0));
            chessboard[0][i] = 1;
            string s(n,'.');
            s[i] = 'Q';
            printf("i: %d\n", i);
			int row = 0;
			int col = i;
            updateChessboard(chessboard, n, row, col);
            printVV(chessboard);
			
        }

        return result;
    }
    int testCase(){
        vector< vector<string> > result;
        int n;
        n = 3;
        result = solveNQueens(n);
        return 0;
    }
    void printVV(vector< vector<int> >& v)
    {
        cout << "[ " <<endl;
        for(int i=0; i<v.size(); i++){
            for(int j=0; j<v[i].size(); j++){
                cout<<v[i][j];
            }
            cout<<" "<<endl;
        }
        cout << "] " << endl;
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