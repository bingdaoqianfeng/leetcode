/**********************************************************************************
*
* Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0?
* Find all unique triplets in the array which gives the sum of zero.
*
* Note:
*
* Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
* The solution set must not contain duplicate triplets.
*
*     For example, given array S = {-1 0 1 2 -1 -4},
*
*     A solution set is:
*     (-1, 0, 1)
*     (-1, -1, 2)
*
*该题的关键是要排序，同时找到排序后的规律。
**********************************************************************************/
class Solution {
public:
    vector< vector<int> > threeSum(vector<int>& nums) {
    	vector< vector<int> > result;
		//通过排序，可以有效降低查找次数.
		sort(nums.begin(), nums.end());
		int len = nums.size();
		for(int i=0; i<len-2; i++){
			if(i>0 && nums[i] == nums[i-1]){ 
				//如果相等，说明nums[i]是nums[i-1]的子集，已经遍历过，不需要在遍历了。
				continue;
			}
			int a = nums[i];
			int low = i+1;
			int high = len-1;
			while(low < high){
				int b = nums[low];
				int c = nums[high];
				if((a + b + c) == 0){
					vector<int> row;
					row.push_back(a);
					row.push_back(b);
					row.push_back(c);
					result.push_back(row);
					//skip the duplication
					while(high>low && (nums[high] == nums[high-1])) high--; //忽略相同的数字。
					while(low<high && (nums[low] == nums[low+1])) low++;
					high--;
					low++;
				}
				else if((a + b + c) > 0){
					//a的值不会变，b已经是可能的最小值了，如果此时还是大于0，那么说明c的值太大了。
					while(high>low && (nums[high] == nums[high-1])) high--; //忽略相同的数字。
					high--;
				}
				else{ //<0
					while(low<high && (nums[low] == nums[low+1])) low++;
					low++;
				}
			}
		}
		return result;
	}
	int testCase(){
		//int a[] = {-1, 0, 1, 2, -1, 1, -4};
        int a[] = {-1, 1, 1, 1, -1, -1, 0,0,0};
		vector<int> nums(a, a+sizeof(a)/sizeof(int));
		vector< vector<int> > result = threeSum(nums);
		printMatrix(result);
		return 0;
	}
	void printMatrix(vector< vector<int> > nums){
		for(int i=0; i<nums.size(); i++){
			printf("(");
			for(int j=0; j<nums[i].size(); j++){
				printf("%d, ",nums[i][j]);
			}
			printf(")\n");
		}
	}
};
