/**********************************************************************************
*
* Given a sorted linked list, delete all nodes that have duplicate numbers,
* leaving only distinct numbers from the original list.
*
* For example,
* Given 1->2->3->3->4->4->5, return 1->2->5.
* Given 1->1->1->2->3, return 2->3.
*
*
**********************************************************************************/

class Solution {

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

public:
    int testCase(){
        int n=3;
        vector< vector<int> > matrix = generateMatrix(n, n);
        printVV(matrix);
        return 0;
    }
};
