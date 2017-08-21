/**********************************************************************************
*
* Given a linked list, swap every two adjacent nodes and return its head.
*
* For example,
* Given 1->2->3->4, you should return the list as 2->1->4->3.
*
* Your algorithm should use only constant space. You may not modify the values in the list,
* only nodes itself can be changed.
*
**********************************************************************************/
#include <stdio.h>
class Solution {
public:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };
    ListNode* swapPairs(ListNode* head) {
        ListNode tempHead(-1);
        ListNode *ptr, *pre;
        tempHead.next = head;
        ptr = pre = &tempHead;

        while(ptr){
            if(ptr == pre){
                if(ptr->next)
                    ptr = ptr->next->next;
                else
                    ptr = NULL;
            }
            else{
                //swap
                pre->next->next = ptr->next;
                ptr->next = pre->next;
                pre->next = ptr;

                ptr = pre = pre->next->next;
            }
        }

        return tempHead.next;
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

        ptr = swapPairs(ptr);
        printList(ptr);
        return 0;
    }
};
