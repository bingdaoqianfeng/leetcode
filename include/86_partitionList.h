/********************************************************************************** 
* 
* Given a linked list and a value x, partition it such that all nodes less than x come 
* before nodes greater than or equal to x.
* 
* You should preserve the original relative order of the nodes in each of the two partitions.
* 
* For example,
* Given 1->4->3->2->5->2 and x = 3,
* return 1->2->2->4->3->5.
* 
*               
**********************************************************************************/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:

ListNode *partition(ListNode *head, int x) {
    ListNode fakeHead(0);
    fakeHead.next = head;
    head = &fakeHead;

    ListNode *pos = NULL;
    for(ListNode *p = head; p!=NULL && p->next!=NULL; ){
        if (!pos && p->next->val >= x){
            pos = p;
            p=p->next;
            continue;
        }
        if (pos && p->next->val < x){
            ListNode *pNext = p->next;
            p->next = pNext->next;
            pNext->next = pos->next;
            pos->next = pNext;
            pos = pNext;
            continue;
        }
        p=p->next;
    }

    return head->next;
}

	int testCase(){
        int n=3;
        vector< vector<int> > matrix = generateMatrix(n, n);
        printVV(matrix);
        return 0;
    }
};
