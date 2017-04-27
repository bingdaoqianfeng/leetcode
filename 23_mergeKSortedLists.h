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
class Solution {
public:
	struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
    	ListNode* head = new ListNode(-1);
		return head->next;  
    }
	int testCase(){
		return 0;
	}
};
