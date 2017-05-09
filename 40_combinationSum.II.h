/**********************************************************************************
*
* Given a collection of candidate numbers (C) and a target number (T), find all
* unique combinations in C where the candidate numbers sums to T.
*
* Each number in C may only be used once in the combination.
*
* Note:
*
* > All numbers (including target) will be positive integers.
* > Elements in a combination (a1, a2, … , ak) must be in non-descending order.
*   (ie, a1 ≤ a2 ≤ … ≤ ak).
* > The solution set must not contain duplicate combinations.
*
* For example, given candidate set 10,1,2,7,6,1,5 and target 8,
* A solution set is:
* [1, 7]
* [1, 2, 5]
* [2, 6]
* [1, 1, 6]
*
**********************************************************************************/
class Solution {
public:
    bool recurcombinationSum2(vector< vector<int> >& result, vector<int>& nums, int target, 
							  int index, vector<int> row, int total) {
		if(index >= nums.size() || nums[index] > target || total+nums[index] > target){
			return false;
		}
		for(int i=index; i<nums.size() && nums[i]<=target; i++){
			vector<int> temprow;
			temprow = row;
			temprow.push_back(nums[i]);
		
			if(nums[i] + total > target){
				break;
			}
			else if(nums[i] + total == target){
				int j;
				for(j=0; j<result.size(); j++)
					if(result[j] == temprow)
						break;
				if(j>=result.size())
					result.push_back(temprow);
			}
			else{
				recurcombinationSum2(result, nums, target, i+1, temprow, nums[i] + total);
			}
		}
		return true;
	}

    vector< vector<int> > combinationSum2(vector<int>& candidates, int target) {
		vector< vector<int> > result;
		sort(candidates.begin(), candidates.end());	
		printVector(candidates);	
		printf("target: %d\n",target);

		for(int i=0; i<candidates.size() && candidates[i]<=target; i++){
			vector<int> row;	
			int total;
			total = candidates[i];
			row.push_back(candidates[i]);
			printf("total: %d\n",total);
			printVector(row);	
			
			if(candidates[i] == target){
				result.push_back(row);
				break;
			}
			else
				recurcombinationSum2(result, candidates, target, i+1, row, total);
		}
		return result;
    }
	int testCase(){
		int a[] = {10,1,2,7,6,1,5};
		int target = 8;
		vector<int> candidates(a, a+sizeof(a)/sizeof(int));
		vector< vector<int> > result;
		
		printVector(candidates);	
		result = combinationSum2(candidates, target);
		printVectorVector(result);
		return 0;
	}
	void printVectorVector( vector< vector<int> >&  pt)
    {
        cout << "{ ";
        for(int i=0; i<pt.size(); i++){
        	cout << "[ ";
			for(int j=0; j<pt[i].size(); j++){
            	cout << pt[i][j] << " ";
			}
        	cout << "] ";
        }
        cout << "} " << endl;
    }
	void printVector( vector<int>&  pt)
    {
        cout << "{ ";
        for(int j=0; j<pt.size(); j++){
            cout << pt[j] << " ";
        }
        cout << "} " << endl;
    }
};
