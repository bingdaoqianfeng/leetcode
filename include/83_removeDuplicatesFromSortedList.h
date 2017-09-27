/**********************************************************************************
*
* Given a sorted linked list, delete all duplicates such that each element appear only once.
*
* For example,
* Given 1->1->2, return 1->2.
* Given 1->1->2->3->3, return 1->2->3.
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
