/**
 * Definition for singly-linked list->
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
    void reorderList(ListNode* head) { 
        if(!head->next) return;
        ListNode * fast = head;
        ListNode * mid = head;
        // find middle
        while(fast && fast->next)
        {
            mid = mid->next;
            fast= fast->next->next;
        }
        // Reverse right half
        ListNode *second = mid->next;
        ListNode *reversed_head {};
        mid->next = nullptr;
        
        while(second)
        {
            ListNode * next = second->next;
            second->next = reversed_head;
            reversed_head = second;
            second = next;
        }
        // Linking
        ListNode *curr = head;
        while (reversed_head)
        {
            ListNode * next = curr->next;
            ListNode * next_reversed = reversed_head->next;
            curr->next = reversed_head;
            reversed_head->next = next;
            reversed_head = next_reversed;
            curr = next;
        }
    }
};