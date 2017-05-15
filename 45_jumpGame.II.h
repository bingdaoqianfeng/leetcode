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
    void recjump(vector<int>& nums, int index, int &ministeps, int jumpnum) {
        int step = nums[index];
        if(index+step == nums.size() - 1){
            if(jumpnum+1<ministeps)
                ministeps = jumpnum + 1;
            return;
        }
        while(step > 0){
            if(step+index>nums.size() - 1){
                step--;
            }
            else if(index+step == nums.size() - 1){
                if(jumpnum+1<ministeps)
                    ministeps = jumpnum + 1;
                return;
            }
            else {
                recjump(nums, index+step, ministeps, jumpnum + 1);
                step--;
            }
        }
        return;
    }
    int jump(vector<int>& nums) {
        int ministeps = nums.size()-1;
        recjump(nums, 0, ministeps, 0);
        return ministeps;
    }
    int testCase(){
        int a[] = {2,3,1,1,4};
        vector<int> nums(a, a + sizeof(a)/sizeof(int));
        printVector(nums);
        printf("%d\n", jump(nums));
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
