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
ListNode *deleteDuplicates(ListNode *head) {
    ListNode fake(-1);
    fake.next = head;
    head = &fake;

    ListNode *tail=head;

    bool dup = false;
    for(ListNode *p=head->next;  p && p->next; p=p->next){
        if (dup==false && p->val == p->next->val){
            dup = true;
            continue;
        }
        if (dup==true && p->val != p->next->val){
            dup = false;
            tail->next = p->next;
            continue;
        }
        if (dup==false){
            tail = p;
        }
    }
    if (dup==true){
        tail->next = NULL;
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
