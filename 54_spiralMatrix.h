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
		int rows, cols;
		int type = 0;
		if(matrix.size() == 0)
			return result;
		rows = matrix.size();
		cols = matrix[0].size();
		top = 0;
		bottom = rows - 1;	
		left = 0;
		right = cols - 1;
		while(top<=bottom){
			switch(type%4){
				case 0: //left to right
					for(int i = left; i <= right; i++){
						result.push_back(matrix[top][i]);
					}
					top++;
					break;
				case 1: //top to bottom
					for(int i = top; i <= bottom; i++){
						result.push_back(matrix[i][right]);
					}
					right--;
					break;
				case 2: //right to left
					for(int i = right; i >= left; i--){
						result.push_back(matrix[bottom][i]);
					}
					bottom--;
					break;
				case 3: //bottom to top
					for(int i = bottom; i >= top; i--){
						result.push_back(matrix[i][left]);
					}
					left++;
					break;
			}
			printf("top: %d, bottom: %d, left: %d, right: %d\n", top, bottom, left, right);
			type++;
		}
    	return result;
	}
	int testCase(){
		int a[] = {1,2,3,4,5,6,7,8,9};
		vector< vector<int> > matrix;
		matrix = createVV(a, 9, 3);
		printVV(matrix);

		vector<int> result;
		result = spiralOrder(matrix);
		printVector(result);
		
		int b[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
		matrix.clear();
		matrix = createVV(b, 16, 4);
		printVV(matrix);

		result = spiralOrder(matrix);
		printVector(result);
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
