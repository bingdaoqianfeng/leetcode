/**********************************************************************************
*
* Given a linked list, remove the nth node from the end of list and return its head.
*
* For example,
*
*    Given linked list: 1->2->3->4->5, and n = 2.
*
*    After removing the second node from the end, the linked list becomes 1->2->3->5.
*
* Note:
* Given n will always be valid.
* Try to do this in one pass.
*
*
**********************************************************************************/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <stdio.h>
class Solution {
public:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *ptr, *pre;
        ListNode tempHead(-1);
        tempHead.next = head;
        pre = &tempHead;
        ptr = tempHead.next;

        while(n && ptr){
            ptr = ptr->next;
            n--;
        }

        while(ptr){
            ptr = ptr->next;
            pre = pre->next;
        }

        pre->next = pre->next->next;

        return tempHead.next;
    }

    void printList(ListNode *head){
        while(head){
            printf("%d ", head->val);
            head = head->next;
        }
        printf("\n");
    }

    int testCase(){
        ListNode head(-1);
        ListNode *ptr = NULL;
        int a[] = {1,2,3,4,5};
        //create list
        int len = sizeof(a)/sizeof(int);
        ptr = &head;
        for(int i=0; i<len; i++){
            ListNode *node = new ListNode(a[i]);
            ptr->next = node;
            ptr = node;
        }
        printList(head.next);

        int n = 2;
        printf("n: %d\n", n);
        ptr = removeNthFromEnd(head.next, n);
        printList(ptr);
        return 0;
    }
};
