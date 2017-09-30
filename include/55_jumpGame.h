/**********************************************************************************
*
* Given an array of non-negative integers, you are initially positioned at the first index of the array.
*
* Each element in the array represents your maximum jump length at that position.
*
* Determine if you are able to reach the last index.
*
* For example:
* A = [2,3,1,1,4], return true.
*
* A = [3,2,1,0,4], return false.
*
**********************************************************************************/
class Solution {

public:
    //从第一位开始，得出最大的跳跃值，在该值范围内，找出其中最大的跳跃值作为下一个范围，如此类推，
    // 如果可以到达最后，就返回true,否则，返回 false.
    bool canJump(vector<int>& nums) {
        int len = nums.size();
        if(len == 0 || len == 1)
            return true;
        int jumplen = nums[0];
        for(int i = 0; i<nums.size();){
            if(jumplen>=len - 1){
                printf("i: %d, nums[i]: %d, len: %d\n", i, nums[i], len);
                return true;
            }
            int onejump = jumplen;
            for(int j = i+1; j<=jumplen; j++){
                if(onejump<=nums[j] + j){
                    onejump = nums[j] + j;
                    i = j;
                }
            }
            if(onejump <= jumplen)
                return false;
            jumplen = onejump;
        }
        return true;
    }
    int testCase(){
        //int a[] = {2,3,1,1,4};    //expected true
        int a[] = {3,2,1,0,4};  //expected false
        //int a[] = {0};  //expected true
        //int a[] = {2, 0, 0};  //expected true
        vector<int> nums(a, a+sizeof(a)/sizeof(int));
        printV(nums);
        printf("canJump %d\n",canJump(nums));
        return 0;
    }
    void printV( vector<int>&  pt)
    {
        cout << "[ ";
        for(int j=0; j<pt.size(); j++){
            cout << pt[j] << "  ";
        }
        cout << "] " << endl;
    }
};
