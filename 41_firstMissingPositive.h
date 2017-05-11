/**********************************************************************************
*
* Given an unsorted integer array, find the first missing positive integer.
*
* For example,
* Given [1,2,0] return 3,
* and [3,4,-1,1] return 2.
*
* Your algorithm should run in O(n) time and uses constant space.
*
**********************************************************************************/
class Solution {

public:
/*
 *  Idea:
 *
 *    We can move the num to the place whcih the index is the num.
 *
 *    for example,  (considering the array is zero-based.
 *       1 => A[0], 2 => A[1], 3=>A[2]
 *
 *    Then, we can go through the array check the i+1 == A[i], if not ,just return i+1;
 *
 *    This solution comes from StackOverflow.com
 *    http://stackoverflow.com/questions/1586858/find-the-smallest-integer-not-in-a-list
 *    http://www.cnblogs.com/yuzhangcmu/p/4200096.html
*/
    int firstMissingPositive(vector<int>& nums) {
		if(nums.size() <= 0) return 1;
		for(int i = 0; i<nums.size(); i++){
			while(nums[i] != i+1 && nums[i] > 0){
				int x = nums[i];
				if(nums[i] == nums[x-1] || (x-1)<0 || (x-1)>=nums.size()) {
					break;
				}
				swap(nums[i], nums[x-1]);
			}
		}
		//printVector(nums);
		for(int i = 0; i<nums.size(); i++)
			if(nums[i] != i+1)
				return i+1;
		return nums.size()+1;
    }
	int testCase(){
		//int a[] = {3,4,-1,1};
		//int a[] = {1, 2, 0};
		//int a[] = {1,1};
		int a[] = {0,3};
		vector<int> nums(a, a+sizeof(a)/sizeof(int));
		printVector(nums);
		printf("first missing positive: %d\n", firstMissingPositive(nums));
		
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
