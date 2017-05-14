/**********************************************************************************
*
* Given an array of non-negative integers, you are initially positioned at the first index of the array.
*
* Each element in the array represents your maximum jump length at that position.
*
* Your goal is to reach the last index in the minimum number of jumps.
*
* For example:
* Given array A = [2,3,1,1,4]
*
* The minimum number of jumps to reach the last index is 2.
* (Jump 1 step from index 0 to 1, then 3 steps to the last index.)
*
**********************************************************************************/
class Solution {
public:
    int jump(vector<int>& nums) {
   		return 0; 
    }
	int testCase(){
		int a[] = {2,3,1,1,4};
		vector<int> nums(a, a + sizeof(a)/sizeof(int));
		printVector(nums);	
		return 0;
	}
	void printVector( vector<int>&  pt)
    {
        cout << "{ ";
        for(int j=0; j<pt.size(); j++){
            cout << pt[j] << "  ";
        }
        cout << "} " << endl;
    }
};
