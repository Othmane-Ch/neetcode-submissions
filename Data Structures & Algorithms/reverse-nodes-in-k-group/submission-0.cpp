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

    ListNode * reverseList(ListNode * head, ListNode * new_head)
    {
        auto stop = new_head;
        auto curr = head;
        while(curr != stop)
        {
            auto next = curr->next;
            curr->next = new_head;
            new_head = curr;
            curr = next;
        }
        return new_head;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        auto i = 0;
        auto curr = head;
        auto start_node = head;
        ListNode * prev {}; 
        while(curr)
        {
            curr = curr->next;
            ++i;
            if(i == k) {
                auto next_start = curr->next;
                auto new_head = reverseList(start_node, curr);
                if(prev)
                {
                    prev->next = new_head;
                } else {
                    head = new_head;
                }
                prev = start_node;
                start_node = curr;
                i = 0;
            } 
        }
        return head;
    }
};
