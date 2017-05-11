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
                    printf("[%d, %d]\n", left, right);
                    left = right;
                    max = -1;
                }
                else{
                    printf("now need from right to left, highest: %d\n", highest);
                    break;
                }
            }
        }

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
                        printf("[%d, %d]\n", left, right);
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
        int ret;
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
