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

    void djjump(vector<int>& nums, int index, vector<int>& result){
        if(index<0)
            return;
        int step = nums[index];
        int distance = nums.size() - 1 - index;
        int minijump = INT_MAX;
        while(step > 0){
            if(step>=distance){
                result[index] = 1;
                return;
            }
            if(result[index+step] > 0 && minijump > result[index+step] + 1){
                minijump = result[index+step] + 1;
            }
            step--;
        }
        if(minijump != INT_MAX)
            result[index] = minijump;
        //printf("index: %d, minijump: %d\n", index, minijump);
        return;
    }

/*
*贪心算法在每一步都做出当时看起来最佳的选择。也就是说，它总是做出局部最优的选择，寄希望(证明)这样的选择能够导致全局最优解。
　　贪心算法和动态规划都依赖于最优子结构，也就是一个问题的最优解包含其子问题的最优解。不同的是，动态规划通常需要求解每一个子问题，通过对所有子问题的求解得到最终问题的解。而贪心算法寄希望于通过贪心选择来改进最优子结构，使得每次选择后只留下一个子问题，大大简化了问题的求解过程。所以能够使用贪心算法的问题都包含着一些特殊的条件，需要细心发觉。贪心算法和动态规划的关系使得我们能够得出，在每个贪心算法之下，几乎总有一个更繁琐的动态规划算法。
　　贪心算法的步骤：
　　　　1.将最优化问题转化为这样的形式：对其做出一次选择后，只剩下一个子问题需要求解。
　　　　2.证明做出贪心选择后，原问题总是存在最优解，即贪心选择总是安全的。
　　　　3.证明做出贪心选择后，剩余的子问题满足性质：其最优解与贪心选择的组合即可得到原问题的最优解，这样就得到了最优子结构。
*/
    void Greedyalgorithm(){

    }

    int jump(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        vector<int> result(nums.size(), 0);
        for(int index = nums.size()-2; index>=0; index--)
            djjump(nums, index, result);
        //printVector(result);
        return result[0];
    }
    int testCase(){
        //int a[] = {2,3,1,1,4};
        int a[] = {5,6,4,4,6,9,4,4,7,4,4,8,2,6,8,1,5,9,6,5,2,7,9,7,9,6,9,4,1,6,8,8,4,4,2,0,3,8,5};
        //int a[] = {5,6,4,4,6,9,4,4,7,4,4,8,2,6,8,1,5,9,6,5,2,7,9,7,9,6,9,4,1,6,8,8,4,4,2,0};
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
