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
    ListNode* deleteMiddle(ListNode* head) {
        if(!head || !head->next) return NULL;
        int cnt = 0;
        ListNode* temp = head;
        while(temp)
        {
            cnt++;
            temp = temp->next;
        }
        cnt = cnt/2;
        cnt--;
        temp = head;
        int n = 0;
        while(temp){
            if(n == cnt) break;
            n++;
            temp = temp->next;
        }
        temp->next = temp->next->next;
        return head;
    }
};