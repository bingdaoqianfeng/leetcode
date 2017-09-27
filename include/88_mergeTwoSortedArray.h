/********************************************************************************** 
* 
* Given two sorted integer arrays A and B, merge B into A as one sorted array.
* 
* Note:
*   You may assume that A has enough space (size that is greater or equal to m + n) 
*   to hold additional elements from B. The number of elements initialized in A and B 
*   are m and n respectively.
*               
**********************************************************************************/

class Solution {
public:

/*
这样固然没错，但是还有更简洁的方法，而且不用申请新变量。算法思想是：由于合并后A数组的大小必定是m+n，所以从最后面开始往前赋值，先比较A和B中最后一个元素的大小，把较大的那个插入到m+n-1的位置上，再依次向前推。如果A中所有的元素都比B小，那么前m个还是A原来的内容，没有改变。如果A中的数组比B大的，当A循环完了，B中还有元素没加入A，直接用个循环把B中所有的元素覆盖到A剩下的位置。
*/
void merge(int A[], int m, int B[], int n) {
    int ia = m-1 ;
    int ib = n-1 ;
    int i = m + n - 1;
    for (int i=m+n-1; i>=0; i--){

        if (ia>=0 && ib<0){
            break;
        }
        if (ia<0 && ib>=0){
            A[i] = B[ib--];
            continue;
        }
        if (ia>=0 && ib>=0){
            if (A[ia] > B[ib]){
                A[i] = A[ia--];
            }else{
                A[i] = B[ib--];
            }
        }

    }
}

    int testCase(){
        int a[]={2,4,6,8,10,0,0,0};
    	int b[]={1,3,5};
    	merge(a, 5, b, 3 );
		return 0;
    }
};
