/**********************************************************************************
*
* Given n non-negative integers representing an elevation map where the width of each bar is 1,
* compute how much water it is able to trap after raining.
*
* For example,
* Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
*
*     ^
*     |
*   3 |                       +--+
*     |                       |  |
*   2 |          +--+xxxxxxxxx|  +--+xx+--+
*     |          |  |xxxxxxxxx|  |  |xx|  |
*   1 |   +--+xxx|  +--+xxx+--+  |  +--+  +--+
*     |   |  |xxx|  |  |xxx|  |  |  |  |  |  |
*   0 +---+--+---+--+--+---+--+--+--+--+--+--+----->
*       0  1   0  2  1   0  1  3  2  1  2  1
*
* The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case,
* 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!
*
**********************************************************************************/
class Solution {

public:

    int trap(vector<int>& height) {
        int left, right, highest;
        int max = -1;
        int trapwater = 0;

        /*从左往右查找，直到遇到最高的bar停止查找，并记录下最高bar的位置。
        在这个过程中，所有可以存水的水槽，一定是左侧的bar小于或等于右侧的bar，
        可以存放的水量应该以左侧bar的高度为准*/
        left = 0;
        highest = -1;
        while(left<height.size()){
            if(height[left]>=max){
                max = height[left];
                highest = left;
                left++;
            }
            else{
                //find left higher. now to find right higher
                right = left;
                while(right < height.size()){
                    if(height[right] >= max)
                        break;
                    right++;
                }
                if(right < height.size()){
                    printf("[%d, %d]\n", left-1, right);
                    for(int i = left; i<right; i++){
                        trapwater += height[left-1] - height[i];
                    }
                    left = right;
                    max = -1;
                }
                else{
                    printf("now need from right to left, highest: %d\n", highest);
                    break;
                }
            }
        }

        /*从右往左查找，直到遇到最高的bar停止查找。
        在这个过程中，所有可以存水的水槽，一定是右侧的bar小于或等于左侧的bar，
        可以存放的水量应该以右侧bar的高度为准*/
        if(left<height.size() && highest != -1 ){
            right = height.size() - 1;
            max = -1;
            while(right >= highest){
                if(height[right]>=max){
                    max = height[right];
                    right--;
                }
                else{
                    //find left higher. now to find right higher
                    printf("right: %d\n", right);
                    left = right;
                    while(left >= highest){
                        if(height[left] >= max)
                            break;
                        left--;
                    }
                    if(left >= highest ){
                        printf("[%d, %d]\n", left, right+1);
                        for(int i = left+1; i<=right; i++){
                            trapwater += height[right+1] - height[i];
                        }
                        right = left;
                        max = -1;
                    }
                    else{
                        printf("traverse finished\n");
                        break;
                    }
                }
            }
        }
        return trapwater;
    }
    int testCase(){
        int a[]={0,1,0,2,1,0,1,3,2,1,2,1};
        vector<int> height(a, a+sizeof(a)/sizeof(int));
        printVector(height);
        printIndex(height);
        printf("trap water: %d\n", trap(height));
        return 0;
    }

    void printIndex( vector<int>&  pt)
    {
        cout << "{ ";
        for(int j=0; j<pt.size(); j++){
            cout << j << "  ";
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
