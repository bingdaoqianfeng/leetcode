/********************************************************************************** 
* 
* Given a collection of distinct numbers, return all possible permutations.
* 
* For example,
* [1,2,3] have the following permutations:
* [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
* 
**********************************************************************************/
class Solution {
public:
    vector< vector<int> > permute(vector<int>& nums) {
        vector< vector<int> > result;
		return result;
    }
	int testCase(){
		int a[] = {1,2,3};
		vector<int> nums(a, a+sizeof(a)/sizeof(int));
        vector< vector<int> > result;
		result = permute(nums);	
		return 0;
	}
};
