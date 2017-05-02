/**********************************************************************************
*
* Given a set of candidate numbers (C) and a target number (T), find all unique combinations
* in C where the candidate numbers sums to T.
*
* The same repeated number may be chosen from C unlimited number of times.
*
* Note:
*
* All numbers (including target) will be positive integers.
* Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
* The solution set must not contain duplicate combinations.
*
* For example, given candidate set 2,3,6,7 and target 7,
* A solution set is:
* [7]
* [2, 2, 3]
*
**********************************************************************************/
class Solution {
public:
    bool recursivecombinationSum(vector<int> candidiates, vector< vector<int> >& result, map<int, int> mymap, int target, vector<int> row, map<int, int>& targetmap) {
		if(target == 0){
			result.push_back(row);
			targetmap[target] = target;
			printf("target: %d\n", target);
			return true;
		}
		if(target<0)
			return false;	
		
		if(targetmap.count(target))
			return true;	
	
		for(int i=candidiates.size()-1; i>=0; i--){
			if(candidiates[i]>target)
				continue;
			vector<int> a = row;
			a.push_back(candidiates[i]);
			if(recursivecombinationSum(candidiates, result, mymap, target-candidiates[i], a, targetmap)){
				targetmap[target] = target;
				printf("target: %d\n", target);
			}
		}
		return true;
	}
    
	vector< vector<int> > combinationSum(vector<int>& candidates, int target) {
		vector< vector<int> > result;
		map<int, int> mymap;
		map<int, int> targetmap;
		vector<int> a;
		for(int i=0; i<candidates.size(); i++){
			mymap[candidates[i]] = candidates[i];
		}
		
		recursivecombinationSum(candidates, result, mymap, target, a, targetmap);	
    	return result;
	}
	int testCase(){
		int a[] = {2,3,6,7};
		int target = 7;
		int len = sizeof(a)/sizeof(int);
		vector<int> candidates(a, a+len);
		vector< vector<int> > result;
		result = combinationSum(candidates, target);
		printvector(candidates, target, result);
		return 0;
	}
	
	void printvector(vector<int> candidates, int target, vector< vector<int> > result){
		for(int i=0; i<candidates.size(); i++){
			printf("%d ", candidates[i]);
		}
		printf("\ntarget: %d \n", target);

		for(int i=0; i<result.size(); i++){
			for(int j=0; j<result[i].size(); j++){
				printf("%d ", result[i][j]);
			}
			printf("\n");
		}
	}
};
