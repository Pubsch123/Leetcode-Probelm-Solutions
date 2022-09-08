/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL) return head;
        ListNode* pref = new ListNode(-1);
        ListNode* suff = new ListNode(-2);
        ListNode* tmp = pref;
        ListNode* ptr = suff;
        while(head)
        {
            if(head->val < x)
            {
                pref->next = new ListNode(head->val);
                pref = pref->next;
            }
            else
            {
                suff->next = new ListNode(head->val);
                suff = suff->next;                                
            }
            head = head->next;
        }
        pref->next = ptr->next;
        return tmp->next;
    }
};