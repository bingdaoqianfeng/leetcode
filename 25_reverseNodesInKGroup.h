/********************************************************************************** 
*
* Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
*
* If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
*
* You may not alter the values in the nodes, only nodes itself may be changed.
*
* Only constant memory is allowed.
*
* For example,
* Given this linked list: 1->2->3->4->5
*
* For k = 2, you should return: 2->1->4->3->5
*
* For k = 3, you should return: 3->2->1->4->5
*
**********************************************************************************/
class Solution {

public:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };

    ListNode* reverseKGroup(ListNode* head, int k) {
    /*该问题的解题思路与删除链表倒数第n个节点的思路一样*/
	    return head;
    }

    void printList(ListNode *head){
        while(head){
            printf("%d ", head->val);
            head = head->next;
        }
        printf("\n");
    }

    //create list
    ListNode* creatList(int a[], int len){
        ListNode head(-1);
        ListNode *ptr = NULL;
        ptr = &head;
        for(int i=0; i<len; i++){
            ListNode *node = new ListNode(a[i]);
            ptr->next = node;
            ptr = node;
        }
        return head.next;
    }
    int testCase(){
        ListNode *ptr = NULL;
        int a[] = {1,3,5,7,9};
        int len = sizeof(a)/sizeof(int);
        ptr = creatList(a, len);
        printList(ptr);

        int k = 2;
        ptr = reverseKGroup(ptr, k);
        printList(ptr);
        return 0;
    }
};
