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
    vector<int> nextLargerNodes(ListNode* head) {
        if(head->next == NULL) return {0};
        ListNode* ptr = NULL;
        ListNode* node = head;
        vector<int> ans;
        while(node)
        {
            ptr = node->next;
            int value = 0;
            while(ptr)
            {
                if(ptr->val > node->val)
                {
                    value = ptr->val;
                        break;
                }
                ptr = ptr->next;
            }
            ans.push_back(value);
            node = node->next;
        }
        return ans;
    }
};