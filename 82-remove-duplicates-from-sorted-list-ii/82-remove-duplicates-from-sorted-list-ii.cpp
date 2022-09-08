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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* ptr = head;
        int v = -1;
        int cnt=0;
        ListNode* nptr = new ListNode(-1);
        ListNode* tmp = nptr;
        while(ptr)
        {
            v = ptr->val;
            while(ptr && ptr->val == v)
            {
                cnt++;
                ptr = ptr->next;
            }
            if(cnt == 1)
            {
                // cout<<v<<" ";
                nptr->next = new ListNode(v);
                nptr = nptr->next;
            }
            cnt=0;
        }
        return tmp->next;
    }
};