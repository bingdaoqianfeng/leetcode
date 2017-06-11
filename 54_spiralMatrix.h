/********************************************************************************** 
* 
* Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
* 
* For example,
* Given the following matrix:
* 
* [
*  [ 1, 2, 3 ],
*  [ 4, 5, 6 ],
*  [ 7, 8, 9 ]
* ]
* 
* You should return [1,2,3,6,9,8,7,4,5].
*
**********************************************************************************/
class Solution {
public:
    vector<int> spiralOrder(vector< vector<int> >& matrix) {
    	vector<int> result;
		int top, bottom, left, right;
		top = 0;
		
		for(int row = 0; row < matrix.size(); row++){
			vector<int> row = matrix[row];
			for(int col = 0; col < ){
				
			}
		}   
    }
	int testCase(){
		int a[] = {1,2,3,4,5,6,7,8,9};
		vector< vector<int> > matrix;
		matrix = createVV(a, 9, 3);
		printVV(matrix);

		vector<int> result;
		result = spiralOrder(matrix);
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
