/**********************************************************************************
*
* Suppose a sorted array is rotated at some pivot unknown to you beforehand.
*
* (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
*
* You are given a target value to search. If found in the array return its index, otherwise return -1.
*
* You may assume no duplicate exists in the array.
*
**********************************************************************************/
/*
*解法
*这道题目在LeetCode当中属于Hard难度的题目，其难点主要在于思维难度，
*这个问题是从标准的二分查找问题引申而出，但是难度却比二分查找难上不少，对于二分查找不熟悉的同学可以先行参考二分查找，来了解一下关于本题的基本知识。
*在二分查找的基础上，本题对原本的“有序序列”做了旋转操作，即将整个序列头尾相接视作一个环，然后旋转一定度数，再拆开来形成一个新的序列。
*这个序列满足这样的特征，ak+1<ak+2<...<an<a1<a2<...<ak，即从第k+1个数开始分为了两段（1..k, k+1..n），且第一段的所有数字都大于第二段的所有数字。
*那么对于这样的问题，我们该如何解决呢？
*下面我们来介绍两种不同的做法：
*/
class Solution {

public:

/*
*解法1
*
*因为对于一般有序序列的查找是我们掌握范围之内的问题，所以我们不妨将这个经过旋转操作的序列，再进行一定程度的旋转，使其变回一个正常的有序序列，然后就可以在这个正常的有序序列上进行二分查找。
*那么关键在于，怎么样使其变回一个正常的有序序列呢？
*一个明显的思路就是找到最小的数字，将其旋转回序列的第一个位置，这样就可以得到一个正常的有序序列。
*于是问题就变成了怎么样在这样一个经过了旋转的序列中找到最小的值呢？
*我们仍然可以尝试使用二分查找的方法：
*首先，将问题抽象化，对于一个区间[l, r]，我们希望能够找到这段区间中最小数的坐标，不妨称为q[l, r]，
*令 m = (l + r) / 2， 首先我们来看这段区间的构成：
*    如果 a[l] < a[r]，说明这段区间是有序的，容易知道 q[l, r] = l
*    如果 a[l] > a[r]，说明这段区间是由两段有序区间组成的，此时我们分情况讨论：
*       2.1 如果 a[m] >= a[l]，说明 m 处于左侧（即较高）的一段有序区间中，因为最小值一定在较低的有序区间中，我们可以知道 q[l, r] = q[m + 1, r]。
*       2.2 如果 a[m] < a[l]，说明 m 处于右侧（即较低）的一段有序区间中，但因为 a[m] 一定满足 a[m] <= a[r]，即[m + 1, r]中的所有元素都不会是最小值，我们可以知道q[l, r] = q[l, m]。
*由于在这样的处理中，每次问题的规模都被缩小了一半，所以最终我们一定会遇到一个问题q[l, r]满足l=r，此时我们就可以知道区间中最小数的坐标为l。
*在知道了最小数的坐标之后，我们就可以轻易的将其回复成原来的有序序列，然后在这个有序序列的基础上进行二分查找，来找到我们想要的元素。
*/
/*
在使用了二分法来查找最小值之后，我们不免产生这样的疑问，是不是可以直接通过二分法来找到我们想要的数呢？
答案是可以的，同之前一样，我们将问题抽象化，对于一个区间[l, r]，我们希望能够找到这段区间中等于某个特定数target的坐标，不妨称为q[l, r]，
令 m = (l + r) / 2， 首先我们来看这段区间的构成：
    如果 a[m] == target，大家应该知道怎么做
    如果 a[l] < a[r]，说明这段区间是有序的，我们将 a[m] 与 target 进行比较
1.1 如果 a[m] < target，容易知道 q[l, r] = q[l, m - 1]
1.2 如果 a[m] > target，容易知道 q[l, r] = q[m + 1, r]
    如果 a[l] > a[r]，说明这段区间是由两段有序区间组成的，此时我们分情况讨论：
2.1 如果 a[m] >= a[l]，说明 m 处于左侧（即较高）的一段有序区间中，此时：
2.1.1 如果 target > a[m]，我们可以知道 a[l .. m - 1] < a[m] < target，都肯定不为答案，即 q[l, r] = q[m + 1, r]
2.1.2 如果 target < a[l]，我们可以知道 a[l + 1 .. m] > a[l] > target，都肯定不为答案，即 q[l, r] = q[m + 1, r]
2.1.3 否则有 a[l] <= target < a[m]， 即 q[l, r] = q[l, m - 1]
2.2 如果 a[m] < a[l], 说明 m 处于右侧（即较低）的一段有序区间中，此时仿照 2.1 的讨论，我们可以知道
2.2.1 如果 target < a[m], 有 q[l, r] = q[l, m - 1]
2.2.2 如果 target > a[r], 有 q[l, r] = q[l, m - 1]
2.2.3 否则 q[l, r] = q[m + 1, r]
由于在这样的处理中，每次问题的规模都被缩小了一半，所以最终我们一定会遇到一个问题 q[l, r] 满足 l >= r，此时我们就检查 l, r 是否相同并且 a[l], target 是否相同来得出答案了。
*/

    int search(vector<int>& nums, int target) {
        int left, mid, right;
        if(nums.size() == 0)
            return -1;
        left = 0;
        right = nums.size() - 1;
        while(left<=right){
            mid = (left + right)/2;
            //printf("before left:%d, mid:%d, right:%d\n",left, mid, right);
            if(nums[mid] == target)
                return mid;
            if(nums[left]<=nums[right]){
                if(nums[mid]<target)
                    left = mid + 1;
                else
                    right = mid - 1;
            }
            else{
                if(nums[mid] <= nums[right]){//mid的右边是升序的队列
                    if(nums[mid]>target){
                        right = mid - 1;
                    }
                    else if(nums[mid]<target && target<=nums[right]){
                        left = mid + 1;
                    }
                    else{
                        right = mid - 1;
                    }
                }
                else{//mid的左边是升序的队列
                    if(nums[left] <= target && target < nums[mid] ){
                        right = mid - 1;
                    }
                    else{
                        left = mid + 1;
                    }
                }
            }
            //printf("after left:%d, mid:%d, right:%d\n",left, mid, right);
        }
        return -1;
    }
    int testCase(){
        printf("--------------------------------------\n");
        int cnt = 2;//20;
        vector<int> a(cnt);
        //for(int i=0; i<a.size(); i++){
        //    a[i]=i*2;
        //}
        a[0] = 3;
        a[1] = 1;
        printArray(a);
        int rotate = random() % cnt;
        rotate=2;
        //printf("rotate=%d\n", rotate);
        //rotate_array(a, rotate);
        printArray(a);
        int target = random() % (2*cnt);
        //target=6;
        target=1;
        printf("target=%d\n", target);

        int idx = search(a, target);
        if ( idx<0 ){
            printf("not found!\n");
        }else{
            printf("a[%d] = %d\n", idx, a[idx]); 
        }
        return 0;
    }

    void rotate_array(vector<int> &a, int pos){
        int i, from=0;
        int n = a.size();
        pos = pos % n;
        if (n<=0) return;

        int tmp = a[0];

        for(int i=0, step=0; step<n && i<pos; step++){
            int to;
            if (from-pos < 0) {
                to = n-pos+from;
            }else{
                to = from-pos;
            }
            int t ;
            t = a[to];
            a[to] = tmp;
            tmp = t;
            from = to;
            if ( to == i ){
                i++;
                from++;
                tmp = a[from];
            }
        }
    }

    void printArray(vector<int> a) {
        printf("{");
        for(int i=0; i<a.size(); i++) {
            printf("%d, ", a[i]);
        }
        printf("}\n");
    }
};
