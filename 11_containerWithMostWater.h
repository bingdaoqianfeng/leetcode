/**********************************************************************************
*
* Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai).
* n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0).
*
* Find two lines, which together with x-axis forms a container, such that the container contains the most water.
*
* Note: You may not slant the container.
*
*
**********************************************************************************/
class Solution {
public:
    //从左向右，遍历所有可能的情况。没有通过的原因是时间超时.
    int maxArea1(vector<int>& height) {
        int maxval = 0, leftval = 0;
        int tempval = 0;
        for(int i=0; i<height.size(); i++){
            leftval = height[i];
            for(int j=i; j<height.size(); j++){
                if(height[j]<leftval){
                    tempval = height[j]*(j-i);
                }
                else{
                    tempval = leftval*(j-i);
                }
                if(tempval>maxval)
                    maxval = tempval;
            }
        }
        return maxval;
    }

    int maxArea(vector<int>& height) {
        int maxval = 0;
        int tempval = 0;
        int left = 0, right = height.size()-1;
        int leftmaxval = 0, rightmaxval = 0;
        leftmaxval=height[left];
        rightmaxval=height[right];
        while(left<right){
            if(height[left]<height[right]){
                tempval = height[left]*(right-left);
                while(left<right && height[left]<=leftmaxval){
                    left++;
                }
                leftmaxval = height[left];
            }
            else{
                tempval = height[right]*(right-left);
                while(left<right && height[right]<=rightmaxval){
                    right--;
                }
                rightmaxval = height[right];
            }
            if(maxval<tempval)
                maxval = tempval;
        }
        return maxval;
    }
    int testCase(){
        //int myints[] = {1,1};
        int myints[] = {3,2,1,3};
        vector<int> height(myints,myints+sizeof(myints)/sizeof(int));
        cout<<maxArea(height)<<endl;
        return 0;
    }
};
