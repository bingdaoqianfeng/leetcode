/**********************************************************************************
*
* Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = new ListNode(-1);
        int n = 0;
        ListNode *ptr = head;
        while(n<lists.size()){
            n = 0;
            ListNode *node = NULL;
            int index = 0;
            for(int i=0; i<lists.size(); i++){
                if(lists[i] == NULL){
                    n++;
                    continue;
                }
                if(node == NULL){
                    node = lists[i];
                    index = i;
                }
                else if(node->val > lists[i]->val){
                    node = lists[i];
                    index = i;
                }
            }
            if(node){
                ptr->next = node;
                ptr = ptr->next;
                lists[index] = node->next;
                node->next= NULL;
            }
        }
        return head->next;
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
        vector<ListNode*> myvect;
        ListNode *ptr = NULL;
        int a[] = {1,3,5,7,9};
        int len = sizeof(a)/sizeof(int);
        ptr = creatList(a, len);
        printList(ptr);
        myvect.push_back(ptr);

        int b[] = {2,4,6,8,10};
        len = sizeof(b)/sizeof(int);
        ptr = creatList(b, len);
        printList(ptr);
        myvect.push_back(ptr);

        ptr = mergeKLists(myvect);
        printList(ptr);
        return 0;
    }
};
