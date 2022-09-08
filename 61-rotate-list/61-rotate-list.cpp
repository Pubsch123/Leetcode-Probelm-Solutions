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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL) return head;
        ListNode* ptr = head;
        ListNode* nptr = NULL;
        int t = 0;
        while(ptr)
        {
            t++;
            ptr = ptr->next;
        }
        ptr = head;
        k %= t;
        int n = t-k;
        if(n == t)
            return head;
        int cnt = 0;
        while(ptr)
        {
            cnt++;
            if(cnt == n)
            {
                nptr = ptr->next;
                ptr->next = NULL;
                break;
            }
            ptr = ptr->next;
        }
        ListNode* tmp = nptr;
        while(tmp->next)
            tmp = tmp->next;
        tmp->next = head;
        return nptr;
    }
};