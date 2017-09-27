/**********************************************************************************
 *
 * Given n non-negative integers representing the histogram's bar height where the width of each bar is 1,
 * find the area of largest rectangle in the histogram.
 *
 *                    6
 *                  +---+
 *               5  |   |
 *              +---+   |
 *              |   |   |
 *              |   |   |
 *              |   |   |     3
 *              |   |   |   +---+
 *        2     |   |   | 2 |   |
 *      +---+   |   |   +---+   |
 *      |   | 1 |   |   |   |   |
 *      |   +---+   |   |   |   |
 *      |   |   |   |   |   |   |
 *      +---+---+---+---+---+---+
 *
 * Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].
 *
 *
 *                    6
 *                  +---+
 *               5  |   |
 *              +-------|
 *              |-------|
 *              |-------|
 *              |-------|     3
 *              |-------|   +---+
 *        2     |-------| 2 |   |
 *      +---+   |-------|---+   |
 *      |   | 1 |-------|   |   |
 *      |   +---|-------|   |   |
 *      |   |   |-------|   |   |
 *      +---+---+---+---+---+---+
 *
 *
 * The largest rectangle is shown in the shaded area, which has area = 10 unit.
 *
 * For example,
 * Given height = [2,1,5,6,2,3],
 * return 10.
 *
 *
 **********************************************************************************/

class Solution {
public:

// As we know, the area = width * height
// For every bar, the 'height' is determined by the loweset bar.
//
// 1) We traverse all bars from left to right, maintain a stack of bars. Every bar is pushed to stack once.
// 2) A bar is popped from stack when a bar of smaller height is seen.
// 3) When a bar is popped, we calculate the area with the popped bar as smallest bar.
// 4) How do we get left and right indexes of the popped bar –
//    the current index tells us the ‘right index’ and index of previous item in stack is the ‘left index’.
//
//
// In other word, the stack only stores the incresing bars, let's see some example
//
// Example 1
// ---------
// height = [1,2,3,4]
//
//    stack[] = [ 0, 1, 2, 3 ], i=4
//
//    1) pop 3,  area = height[3] * 1 = 4
//    2) pop 2,  area = height[2] * 2 = 4
//    3) pop 1,  area = height[1] * 3 = 6
//    4) pop 0,  area = height[0] * 4 = 4
//
/*
1、如果已知height数组是升序的，应该怎么做？

比如1,2,5,7,8

那么就是(1*5) vs. (2*4) vs. (5*3) vs. (7*2) vs. (8*1)

也就是max(height[i]*(size-i))

2、使用栈的目的就是构造这样的升序序列，按照以上方法求解。

但是height本身不一定是升序的，应该怎样构建栈？

比如2,1,5,6,2,3

（1）2进栈。s={2}, result = 0

（2）1比2小，不满足升序条件，因此将2弹出，并记录当前结果为2*1=2。

将2替换为1,1也进栈，s={1,1}, result = 2

（3）5比1大，满足升序条件，进栈。s={1,1,5},result = 2

（4）6比5大，满足升序条件，进栈。s={1,1,5,6},result = 2

（5）2比6小，不满足升序条件，因此将6弹出，并记录当前结果为6*1=6。s={1,1,5},result = 6

2比5小，不满足升序条件，因此将5弹出，并记录当前结果为5*2=10（因为已经弹出的5,6是升序的）。s={1,1},result = 10

2比1大，将弹出的5,6替换为2重新进栈。s={1,1,2,2,2},result = 10

（6）3比2大，满足升序条件，进栈。s={1,1,2,2,2,3},result = 10

栈构建完成，满足升序条件，因此按照升序处理办法得到上述的max(height[i]*(size-i))=max{3*1, 2*2, 2*3, 2*4, 1*5, 1*6}=8<10

综上所述，result=10
*/
#if 0
int largestRectangleArea(vector<int> &height) {
    if (height.size()<=0) return 0;
    //Create an empty stack.
    stack<int> mystack;
    //add a flag as a trigger if the end bar is met, and need to check the stack is empty of not .
    height.push_back(0);
    int maxArea = 0;
    for(int i=0; i<height.size(); i++){
        //If stack is empty or height[i] is higher than the bar at top of stack, then push ‘i’ to stack.
        if ( mystack.size()<=0 || height[i] >= height[mystack.top()] ) {
            mystack.push(i);
            continue;
        }
        //If this bar is smaller than the top of stack, then keep removing the top of stack while top of the stack is greater. 
        //Let the removed bar be height[top]. Calculate area of rectangle with height[top] as smallest bar. 
        //For height[top], the ‘left index’ is previous (previous to top) item in stack and ‘right index’ is ‘i’ (current index).
        int topIdx = mystack.top();
        mystack.pop();
        int area = height[topIdx] * (mystack.size()==0 ? i : i - mystack.top() - 1 );
        if ( area > maxArea ) {
            maxArea = area;
        }
        //one more time. Because the stack might still have item.
        i--;
    }

    return maxArea;
}
#endif
int largestRectangleArea(vector<int> &height) {
    int ret = 0;
        stack<int> stk;
        for(int i = 0; i < height.size(); i ++)
        {
            if(stk.empty() || stk.top() <= height[i])
                stk.push(height[i]);
            else
            {
                int count = 0;
                while(!stk.empty() && stk.top() > height[i])
                {
                    count ++;
                    ret = max(ret, stk.top()*count);
                    stk.pop();
                }
                while(count --)
                    stk.push(height[i]);
                stk.push(height[i]);
            }
        }
        int count = 1;
        while(!stk.empty())
        {
            ret = max(ret, stk.top()*count);
            stk.pop();
            count ++;
        }
        return ret;
}

    int testCase(){
        //int a[] = {2,1,3,1};
        int a[] = {2,1,5,6,2,3};
        vector<int> v(a, a + sizeof(a)/sizeof(int));
        cout << largestRectangleArea(v) << endl;
        return 0;
    }
};
