/**************************************************************************************
*There are two sorted arrays nums1 and nums2 of size m and n respectively.
*
*Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
*
*Example 1:
*nums1 = [1, 3]
*nums2 = [2]
*
*The median is 2.0
*Example 2:
*nums1 = [1, 2]
*nums2 = [3, 4]
*
*The median is (2 + 3)/2 = 2.5
*
* 解题思路 ：从两个数组的开头开始同时遍历，寻找中间数值。这里需要处理几种情况：
*1，一个数组提前遍历到末尾还没有找到中间值；2，对于偶数，中间两个值在两个数组中；
*3，注意对边界的处理。
**************************************************************************************/
class Solution {
public:

/*
方案1：假设两个数组总共有n个元素，那么显然我们有用O(n)时间和O(n)空间的方法：用merge sort的思路排序，排序好的数组取出下标为k-1的元素就是我们需要的答案。
这个方法比较容易想到，但是有没有更好的方法呢？
方案2：我们可以发现，现在我们是不需要“排序”这么复杂的操作的，因为我们仅仅需要第k大的元素。我们可以用一个计数器，记录当前已经找到第m大的元素了。
同时我们使用两个指针pA和pB，分别指向A和B数组的第一个元素。使用类似于merge sort的原理，如果数组A当前元素小，那么pA++，同时m++。
如果数组B当前元素小，那么pB++，同时m++。最终当m等于k的时候，就得到了我们的答案——O(k)时间，O(1)空间。
*/

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len = 0, mid = 0;
        bool isodd = true;
        double midval = 0.0;
        int i = 0, j=0, index = -1;

        len = nums1.size() + nums2.size();
        if(len == 0)
            return 0;

        if(len%2 == 0){
            isodd = false;
            mid = len/2 - 1;
        }
        else{
            mid = len/2;
        }
        printf("mid=%d, len=%d, nums1.size=%d, nums2.szie=%d \n",
            mid, len, nums1.size(), nums2.size());
        while(index<mid && i<nums1.size() && j<nums2.size()){
            if(nums1[i]<=nums2[j]){
                midval = nums1[i];
                i++;
            }
            else{
                midval = nums2[j];
                j++;
            }
            index++;
        }
        printf("midval=%f, i=%d, j=%d, index=%d\n", midval, i, j, index);
        if(index<mid){
            //don't find mid value
            if(i<nums1.size()){
                while(index<mid && i<nums1.size()){
                    midval = nums1[i];
                    i++;
                    index++;
                }
                if(!isodd){
                    midval = midval + nums1[i];
                    midval = midval/2.0;
                }
            }
            if(j<nums2.size()){
                while(index<mid && j<nums2.size()){
                    midval = nums2[j];
                    j++;
                    index++;
                }
                if(!isodd){
                    midval = midval + nums2[j];
                    midval = midval/2.0;
                }
            }
        }
        else{
            //found mid value
            if(!isodd){
                if(i<nums1.size() && j<nums2.size()){
                    if(nums1[i]<=nums2[j])
                        midval = midval + nums1[i];
                else
                    midval = midval + nums2[j];
                    midval = midval/2.0;
                }
                else if(i<nums1.size()){
                    midval = (midval + nums1[i])/2.0;
                }
                else if(j<nums2.size()){
                    midval = (midval + nums2[j])/2.0;
                }
            }
        }
        return midval;
    }

	int testCase(){
		{//case 1
			int r1[] = {1};
        	int r2[] = {2};
			vector<int> nums1(r1,r1+sizeof(r1)/sizeof(int));
			vector<int> nums2(r2,r2+sizeof(r2)/sizeof(int));
			printf("Median is 1.5 = %f\n", findMedianSortedArrays(nums1, nums2));	
		}
		{//case 2
			int r1[] = {1, 12, 15, 26, 38};
        	int r2[] = {2, 13, 17, 30, 45, 50};
			vector<int> nums1(r1,r1+sizeof(r1)/sizeof(int));
			vector<int> nums2(r2,r2+sizeof(r2)/sizeof(int));
			printf("Median is 17 = %f\n", findMedianSortedArrays(nums1, nums2));	
		}
		{//case 3
			int r1[] = {1, 12, 15, 26, 38};
        	int r2[] = {2, 13, 17, 30, 45 };
			vector<int> nums1(r1,r1+sizeof(r1)/sizeof(int));
			vector<int> nums2(r2,r2+sizeof(r2)/sizeof(int));
			printf("Median is 16 = %f\n", findMedianSortedArrays(nums1, nums2));	
		}
		{//case 4
			int r1[] = {1, 2, 5, 6, 8 };
        	int r2[] = {13, 17, 30, 45, 50};
			vector<int> nums1(r1,r1+sizeof(r1)/sizeof(int));
			vector<int> nums2(r2,r2+sizeof(r2)/sizeof(int));
			printf("Median is 10.5 = %f\n", findMedianSortedArrays(nums1, nums2));	
		}
		{//case 5
			int r1[] = {1, 2, 5, 6, 8, 9, 10 };
        	int r2[] = {13, 17, 30, 45, 50};
			vector<int> nums1(r1,r1+sizeof(r1)/sizeof(int));
			vector<int> nums2(r2,r2+sizeof(r2)/sizeof(int));
			printf("Median is 9.5 = %f\n", findMedianSortedArrays(nums1, nums2));	
		}
		{//case 6
			int r1[] = {1, 2, 5, 6, 8, 9 };
        	int r2[] = {13, 17, 30, 45, 50};
			vector<int> nums1(r1,r1+sizeof(r1)/sizeof(int));
			vector<int> nums2(r2,r2+sizeof(r2)/sizeof(int));
			printf("Median is 9 = %f\n", findMedianSortedArrays(nums1, nums2));	
		}
		{//case 7
			int r1[] = {1, 2, 5, 6, 8 };
        	int r2[] = {11, 13, 17, 30, 45, 50};
			vector<int> nums1(r1,r1+sizeof(r1)/sizeof(int));
			vector<int> nums2(r2,r2+sizeof(r2)/sizeof(int));
			printf("Median is 11 = %f\n", findMedianSortedArrays(nums1, nums2));	
		}
		{//case 8
			int r1[] = {1};
        	int r2[] = {2,3,4};
			vector<int> nums1(r1,r1+sizeof(r1)/sizeof(int));
			vector<int> nums2(r2,r2+sizeof(r2)/sizeof(int));
			printf("Median is 2.5 = %f\n", findMedianSortedArrays(nums1, nums2));	
		}
		return 0;
	}
};
