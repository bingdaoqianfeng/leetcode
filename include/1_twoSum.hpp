/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> result;
        map<int, int> index;
        for(int i=0; i<n; i++){
            if(index.count(nums[i])!=0){
                //if exists
                result.push_back(index[nums[i]]);
                result.push_back(i);
                break;
            }
            index[target - nums[i]] = i;
        }
        return result;
    }

    int testCase(){
        int a[] = {2, 7, 11, 15};
        int target = 9;
        vector<int> nums(a, a + sizeof(a)/sizeof(int));
        vector<int> result;
        printf("target: %d\n", target);
        printVector(nums);

        result = twoSum(nums, target);
        printVector(result);
        return 0;
    }
    void printVector( vector<int>&  pt)
    {
        cout << "[ ";
        for(int i=0; i<pt.size(); i++)
            cout << pt[i] <<" ";
        cout << "] " << endl;
    }
};
