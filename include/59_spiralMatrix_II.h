/********************************************************************************** 
* 
* Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.
* 
* For example,
* Given n = 3,
* 
* You should return the following matrix:
* 
* [
*  [ 1, 2, 3 ],
*  [ 8, 9, 4 ],
*  [ 7, 6, 5 ]
* ]
* 
*               
**********************************************************************************/

class Solution {
public:
	vector<vector<int> > generateMatrix(int n, int m) {
    	vector< vector <int> > matrix(n);
    	if (n<=0) return matrix;
    	for(int i=0; i<n; i++){
        	vector<int> v(m);
        	matrix[i] = v;
    	}

    	int row=n, col=m;
    	int r, c;
    	int cnt=1;
    	for (r=0, c=0; r<(row+1)/2 && c<(col+1)/2; r++, c++){
        	//top
        	for(int i=c; i<col-c; i++){
            	matrix[r][i] = cnt++;
        	}
        	//right
        	for(int i=r+1; i<row-r; i++){
            	matrix[i][col-c-1] = cnt++;
        	}
        	//bottom
        	for(int i=col-c-2; row-r-1>r && i>=c; i--){
            	matrix[row-r-1][i] = cnt++;
        	}
        	//left
        	for(int i=row-r-2; col-c-1>c && i>r; i--){
            	matrix[i][c] = cnt++;
        	}

    	}
    	return matrix;
	}	

	int testCase(){
		int n=3;
		vector< vector<int> > matrix = generateMatrix(n, n);	
		printVV(matrix);
		return 0;
	}
	vector< vector<int> > createVV(int a[], int len, int n){
		vector< vector<int> > matrix;
		printf("len: %d, n: %d\n", len, n);
		vector<int> row;
		for(int i=1; i<=len; i++){
			row.push_back(a[i-1]);
			if(i%n == 0){
				matrix.push_back(row);
				row.clear();	
			}
		}
		return matrix;
	}
	void printVV(vector< vector<int> >& v)
	{
			cout << "[ " <<endl;
			for(int j=0; j<v.size(); j++){
					printVector(v[j]);
			}
			cout << "] " << endl;
	}
	void printVector( vector<int>&  pt)
	{
			cout << "[ ";
			for(int j=0; j<pt.size(); j++){
					cout << pt[j] << "  ";
			}
			cout << "] " << endl;
	}
};
