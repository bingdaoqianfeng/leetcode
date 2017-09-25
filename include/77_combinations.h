/********************************************************************************** 
* 
* Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
* 
* For example,
* If n = 4 and k = 2, a solution is:
* 
* [
*   [2,4],
*   [3,4],
*   [2,3],
*   [1,2],
*   [1,3],
*   [1,4],
* ]
* 
*               
**********************************************************************************/

class Solution {
public:
	/*
		这道题让求1到n共n个数字里k个数的组合数的所有情况，还是要用深度优先搜索DFS来解，
        根据以往的经验，像这种要求出所有结果的集合，一般都是用DFS调用递归来解。
	*/
vector<vector<int> > combine(int n, int k) {
    vector<vector<int> > result;
    vector<int> solution;
    getCombination(n, k, solution, result);
    return result;
}

void getCombination(int n, int k, vector<int>& solution, vector< vector<int> >& result ){
    if (k==0){
        //sort to meet LeetCode requirement
        vector<int> v = solution;
        sort(v.begin(), v.end());
        result.push_back(v);
        return;
    }
    for(int i=n; i>0; i--){
        solution.push_back(i);
        getCombination(i-1, k-1, solution, result);
        solution.pop_back();
    }
}
    int testCase(){
        int n=3;
        vector< vector<int> > matrix = generateMatrix(n, n);
        printVV(matrix);
        return 0;
    }
};
