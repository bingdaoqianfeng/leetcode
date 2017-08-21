/********************************************************************************** 
*
* Given a collection of distinct numbers, return all possible permutations.
*
* For example,
* [1,2,3] have the following permutations:
* [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
*
**********************************************************************************/
class Solution {
public:
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
    vector< vector<int> > permute(vector<int>& nums) {
        vector< vector<int> > result;
        map<int, int> mymap;
        vector<int> row;

        recupermute(nums, mymap, result, row);
        return result;
    }
    int testCase(){
        int a[] = {1,2,1,3};
        vector<int> nums(a, a+sizeof(a)/sizeof(int));
        vector< vector<int> > result;
        printVector(nums);

        result = permute(nums);
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
