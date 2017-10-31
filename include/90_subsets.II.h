/********************************************************************************** 
* 
* Given a collection of integers that might contain duplicates, S, return all possible subsets.
* 
* Note:
* 
* Elements in a subset must be in non-descending order.
* The solution set must not contain duplicate subsets.
* 
* For example,
* If S = [1,2,2], a solution is:
* 
* [
*   [2],
*   [1],
*   [1,2,2],
*   [2,2],
*   [1,2],
*   []
* ]
* 
*               
**********************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
vector<vector<int> > subsets(vector<int> &S) {
    vector<vector<int> > result;
    sort(S.begin(), S.end());
    for(int i=0; i<=S.size(); i++){
        vector<vector<int> > r = combine(S, i);
    	printf("begin------i=%d-------\n",i);
    	printResult(r);
    	printf("end------i=%d-------\n",i);
		result.insert(result.end(), r.begin(), r.end());
    }
    return result;
}


vector<vector<int> > combine(vector<int> &v, int k) {
    vector<vector<int> > result;
    vector<int> solution;
    getCombination(v, v.size(), k, solution, result);
    return result;
}

void getCombination(vector<int> &v, int n, int k, vector<int>& solution, vector< vector<int> >& result ){
    if (k==0){
        //sort to meet LeetCode requirement
        vector<int> v = solution;
        sort(v.begin(), v.end());
        result.push_back(v);
        return;
    }
    for(int i=n; i>0; i--){
        solution.push_back(v[i-1]);
        getCombination(v, i-1, k-1, solution, result);
        solution.pop_back();
        //skip the duplication
        while (i>1 && v[i-1]==v[i-2]) i--;
   }
}

void printResult(vector<vector<int> >& result)
{
    for(int i=0; i<result.size(); i++){
        cout << "{";
        for(int j=0; j<result[i].size(); j++){
            cout << " " << result[i][j];
        }
        cout << " }" <<endl;
    }
}

void printArray(vector<int>& v){
    cout << "{";
    for(int i=0; i<v.size(); i++) {
        cout << " " << v[i];
    }
    cout << " }" << endl;
}


    int testCase(){
        //int a[] = {1, 2, 2, 2, 2,};
        int a[] = {1, 2, 3};
    	vector<int> v;
	v.clear();
    //v.insert(v.begin(), a, a+5);
    v.insert(v.begin(), a, a+3);
    printArray(v);
    cout << "--------------------" <<endl;
    vector<vector<int> > r = subsets(v);
    printResult(r);
    cout << "====================" <<endl;
		return 0;
    }
};
