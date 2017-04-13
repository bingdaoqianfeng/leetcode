/**********************************************************************************
*
* You are given two linked lists representing two non-negative numbers.
* The digits are stored in reverse order and each of their nodes contain a single digit.
* Add the two numbers and return it as a linked list.
*
* Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
* Output: 7 -> 0 -> 8
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
class Solution {
    
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *p, *q, *head, *ptr;
        int count = 0, sum1, sum2;
        p = l1;
        q = l2;
        head = new ListNode(0);
        ptr = head;
        while(p || q){
            if(p){
                sum1 = p->val;
                p = p->next;
            }
            else
                sum1 = 0;
            if(q){
                sum2 = q->val;
                q = q->next;
            }
            else
                sum2 = 0;
            count = count + sum1 + sum2;
            ptr->next = new ListNode(count%10);
            ptr = ptr->next;
            count = count/10;
        }
        if(count >0){
            ptr->next = new ListNode(count);
            ptr = ptr->next;
        }
        return head->next;
    }
};
