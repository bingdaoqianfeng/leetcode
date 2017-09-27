/**********************************************************************************
*
* Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle
* containing all ones and return its area.
*
**********************************************************************************/

using namespace std;

// The problem can be convert to the problem - "Largest Rectangle in Histogram"
//   1) we can take each row to calculate each row's histogram.
//   2) using the algorithm of "Largest Rectangle in Histogram" to find the largest area histogram.
//   3) tracking the maximal area.
//
// For the 1), it's easy.
//     heights[i][j] = 1,                     if (i==0)
//     heights[i][j] = heights[i-1][j] + 1;,  if (i>0)
//
// For the 2), please referr to "Largest Rectangle in Histogram"
//

class Solution {
public:

int largestRectangleArea(vector<int> &height) {

    if (height.size()<=0) return 0;

    height.push_back(0);
    vector<int> stack;
    int maxArea=0;

    for(int i=0; i<height.size(); ){
        if (stack.size()==0 || height[i] >= height[ stack.back() ] ){
            stack.push_back(i);
            i++;
        }else{
            int topIdx = stack.back();
            stack.pop_back();
            int area = height[topIdx] * ( stack.size()==0 ? i  : i - stack.back() - 1 );
            if (area > maxArea){
                maxArea = area;
            }
        }
    }
    return maxArea;
}

/*将问题转换成largestRectangleInHistogram的问题，每一层都所谓一个largestRectangleInHistogram的问题处理
这里注意没层加一层，对应的高度也要增加*/
int maximalRectangle(vector<vector<char> > &matrix) {

    if (matrix.size()<=0 || matrix[0].size()<=0) return 0;
    int row = matrix.size();
    int col = matrix[0].size();
    vector< vector<int> > heights(row, vector<int>(col));

    int maxArea = 0;
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++) {
            if (matrix[i][j]=='1'){
                heights[i][j] = (i==0 ? 1 : heights[i-1][j] + 1);
            }
        }
        int area = largestRectangleArea(heights[i]);
        if (area > maxArea){
            maxArea = area;
        }
    }

    return maxArea;

}

    int testCase(){
        int n=3;
        vector< vector<int> > matrix = generateMatrix(n, n);
        printVV(matrix);
        return 0;
    }
};
