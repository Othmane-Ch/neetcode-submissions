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
    // Time  : O(n)
    // Space : O(1)
    bool hasCycle(ListNode* head) {
        if(!head->next) return false;
        ListNode * prev = head;
        while(prev && prev->next && prev->next != head)
        {
            head = head->next;
            prev = prev->next->next;
        }
        return prev && prev->next == head;
    }
};
