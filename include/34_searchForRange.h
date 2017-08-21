/********************************************************************************** 
*
* Given a sorted array of integers, find the starting and ending position of a given target value.
*
* Your algorithm's runtime complexity must be in the order of O(log n).
*
* If the target is not found in the array, return [-1, -1].
*
* For example,
* Given [5, 7, 7, 8, 8, 10] and target value 8,
* return [3, 4].
*
**********************************************************************************/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
		vector<int> result;
		int left, mid, right;		

		if(nums.size() == 0){
			result.push_back(-1);
			result.push_back(-1);
			return result;
		}
		left = 0;
		right = nums.size() - 1;
		while(left<=right){
			mid = (left + right)/2;
			printf("left:%d, mid:%d, right:%d\n", left, mid, right);
			if(nums[mid] == target){
				int i = 0;
				while((mid-i) >= 0 && nums[mid-i] == target){
					i++;
				}
				printf("i: %d\n", i);
				result.push_back(mid - i + 1);
				i = 0;
				while((mid+i) < nums.size() && nums[mid+i] == target){
					i++;
				}
				printf("i: %d\n", i);
				result.push_back(mid + i - 1);
				break;
			}
			if(nums[mid] < target){
				left = mid + 1;
			}
			else{
				right = mid -1;
			}
		}
		if(result.size() == 0){
			result.push_back(-1);
			result.push_back(-1);
		}
			
        return result;
    }
    int testCase(){
        //int a[] = {5, 7, 7, 8, 8, 10};  //target is 8
        int a[] = {0, 0, 0, 1, 2, 3};   //target is 0
        vector<int> nums(a, a+sizeof(a)/sizeof(int));
        int target = 0;

		vector<int> result;
        printVector(nums);
        result = searchRange(nums, target);
        printVector(result);
        return 0;
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
