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
};
