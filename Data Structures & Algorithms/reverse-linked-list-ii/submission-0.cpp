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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head || left == right) return head;
        auto * curr = head;
        int l = 1;

        ListNode dummy(0, head);
        ListNode * prev = &dummy;
        while(l < left)
        {
            prev = curr;
            curr = curr->next;
            ++l;
        }
        ListNode * start = prev;
        while(l <= right && curr)
        {
            auto* next = curr->next;
            curr->next = prev; 
            prev = curr;
            curr = next;
            ++l;
        }
        start->next->next = curr;
        start->next = prev;

        return dummy.next;
    }
};