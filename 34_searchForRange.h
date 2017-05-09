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
        return result;
    }
    int testCase(){
        int a[] = {5, 7, 7, 8, 8, 10};
        vector<int> nums(a, a+sizeof(a)/sizeof(int));
        int target = 8;
        printVector(nums);
        //searchRange(nums, 8);
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
