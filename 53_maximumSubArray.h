/********************************************************************************** 
* 
* Find the contiguous subarray within an array (containing at least one number) 
* which has the largest sum.
* 
* For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
* the contiguous subarray [4,−1,2,1] has the largest sum = 6.
* 
* More practice:
* 
* If you have figured out the O(n) solution, try coding another solution using 
* the divide and conquer approach, which is more subtle.
* 
**********************************************************************************/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
		int maxval = nums[0];
		int left = 0;
		int right = 0;
 		for(int i=0; i<nums.size(); i++){
			if(nums[i]>maxval){
				maxval = nums[i];
				left = right = i;
			}	
			len = nums.size() - i;
			while(len){
				int tempval = 0;
				for(int j=i; j<len; j++){
					tempval += nums[j];	
				}
				if(tempval>maxval){
					maxval = nums[i];
					left = i;
					right = i+len;
				}	
				len--;
			}
		} 
    }
	int testCase(){
		return 0;
	}
};
