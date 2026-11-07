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
    // Time  : O(n + m)
    // Space : O(1)
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int q = 0;
        auto * head = new ListNode();
        auto * curr = head;
        while( curr)
        {
            int num1 = l1 ? l1->val : 0;
            int num2 = l2 ? l2->val : 0;
            int num = num1 + num2 + q;
            
            q = num / 10;
            curr->val = num % 10;
            auto * next = (l1 && l1->next) || (l2 && l2->next) || q ? new ListNode() : nullptr;
            curr->next = next;
            curr = next;
            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
        }
        if(q)
        {
            curr->val = q;
        }
        return head;
    }
};
