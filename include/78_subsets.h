/********************************************************************************** 
* 
* Given a set of distinct integers, S, return all possible subsets.
* 
* Note:
* 
* Elements in a subset must be in non-descending order.
* The solution set must not contain duplicate subsets.
* 
* For example,
* If S = [1,2,3], a solution is:
* 
* [
*   [3],
*   [1],
*   [2],
*   [1,2,3],
*   [1,3],
*   [2,3],
*   [1,2],
*   []
* ]
* 
*               
**********************************************************************************/

class Solution {
public:
/*
循环调用77_combinations.h的实现。
*/
vector<vector<int> > subsets(vector<int> &S) {
    vector<vector<int> > result;
    for(int i=0; i<=S.size(); i++){
        vector<vector<int> > r = combine(S, i);
        result.insert(result.end(), r.begin(), r.end());
    }
    return result;
}

    int testCase(){
        int n=3;
        vector< vector<int> > matrix = generateMatrix(n, n);
        printVV(matrix);
        return 0;
    }
};
