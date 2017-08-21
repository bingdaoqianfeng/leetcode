/********************************************************************************** 
*
* Given a collection of numbers that might contain duplicates, return all possible unique permutations.
*
* For example,
* [1,1,2] have the following unique permutations:
* [1,1,2], [1,2,1], and [2,1,1].
*
**********************************************************************************/
class Solution {

public:
    //递归算法会超时
    void recupermute(vector<int>& nums, map<int, int>& mymap,  vector< vector<int> >& result, vector<int>& row) {
        if(mymap.size() == nums.size()){
            int j;
            for(j = 0; j < result.size(); j++)
                if(result[j] == row)
                    break;
            if(j < result.size())
                return;
            result.push_back(row);
            return;
        }
        for(int i = 0; i < nums.size(); i++){
            if(!mymap.count(i)){
                map<int, int> tempmap = mymap;
                vector<int> temprow = row;
                tempmap[i] = 1;
                temprow.push_back(nums[i]);
                recupermute(nums, tempmap, result, temprow);
            }
        }
        return;
    }
/*
*当n=1时，数组中只有一个数a1，其全排列只有一种，即为a1
*当n=2时，数组中此时有a1a2，其全排列有两种，a1a2和a2a1，那么此时我们考虑和上面那种情况的关系，我们发现，其实就是在a1的前后两个位置分别加入了a2
*当n=3时，数组中有a1a2a3，此时全排列有六种，分别为a1a2a3, a1a3a2, a2a1a3, a2a3a1, a3a1a2, 和 a3a2a1。那么根据上面的结论，实际上是在a1a2和a2a1的基础上在不同的位置上加入a3而得到的。
*_ a1 _ a2 _ : a3a1a2, a1a3a2, a1a2a3
*_ a2 _ a1 _ : a3a2a1, a2a3a1, a2a1a3
*/
    vector< vector<int> > permuteUnique(vector<int>& nums) {
        vector< vector<int> > result;
        map<int, int> mymap;
        vector<int> row;

        recupermute(nums, mymap, result, row);
        return result;
    }
    int testCase(){
        //int a[] = {1,1,2};
        int a[] = {3,3,0,0,2,3,2};
        vector<int> nums(a, a+sizeof(a)/sizeof(int));
        vector< vector<int> > result;
        printVector(nums);

        result = permuteUnique(nums);
        printVectorVector(result);
        return 0;
    }
    void printVectorVector( vector< vector<int> >&  pt)
    {
        cout << "{ " << endl;
        for(int j=0; j<pt.size(); j++){
            printVector(pt[j]);
        }
        cout << "} " << endl;
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
