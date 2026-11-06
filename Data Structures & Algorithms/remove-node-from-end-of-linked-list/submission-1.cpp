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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode * tail = head;
        int sz = 0;
        while(tail)
        {
            tail = tail->next;
            ++sz;
        }
        ListNode dummy(0, head);
        ListNode * prev = &dummy;
        auto curr = head;
        int pos = 0;
        while(pos != sz - n)
        {
            prev = prev->next;
            curr = curr->next;
            ++pos;
        }

        prev->next = curr->next;
        curr->next = nullptr;
        return dummy.next;
    }
};
