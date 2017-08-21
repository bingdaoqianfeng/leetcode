/**********************************************************************************
*
* Given an array S of n integers, find three integers in S such that the sum is
* closest to a given number, target. Return the sum of the three integers.
* You may assume that each input would have exactly one solution.
*
*     For example, given array S = {-1 2 1 -4}, and target = 1.
*
*     The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*
*
**********************************************************************************/
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
		int diff = INT_MAX; //diff表示的是距离，因此必须是整数，不能出现负值。
		int result = 0;
		int len = nums.size();
		sort(nums.begin(), nums.end());
		for(int i=0; i<len-2; i++){
			if(i>0 && nums[i] == nums[i-1]) continue;
			int a = nums[i];
			int low = i+1;
			int high = len-1;
			while(low<high){
				int b = nums[low];
				int c = nums[high];
				int tempval = a + b + c;
				if(tempval == target){
					return target;
				}
				else if(tempval >target){
					if(abs(tempval - target) < diff){
						result = tempval;
						diff = abs(tempval - target);
					}
					while(low<high && nums[high] == nums[high-1]) high--;
					high--;
				}
				else{
					if(abs(target - tempval) < diff){
						result = tempval;
						diff = abs(target - tempval);
					}
					while(low<high && nums[low] == nums[low+1]) low++;
					low++;
				}
				printf("%d + %d + %d =% d, tempval=%d, diff=%d\n",a, b, c, result, tempval, diff);
			}
		}
		return result;
    }
    int testCase(){
        int a[]={-1, 2, 1, -4};
		int target = 1;
		vector<int> nums(a, a+sizeof(a)/sizeof(int));
		printf("input:");
		for(int i=0; i<nums.size(); i++){
			printf("%d, ", nums[i]);
		}
		printf("	target: %d\n", target);
		printf("output is %d \n", threeSumClosest(nums, target));
		return 0;
    }
};
