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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1) return list2;
        if(!list2) return list1;
        ListNode * curr1 = list1;
        ListNode * curr2 = list2;
        ListNode * prev = new ListNode(0, list1->val <= list2->val ? list1 : list2);

        while(curr1 && curr2)
        {
            if(curr1 && curr1->val <= curr2->val)
            {
                prev = curr1;
                curr1 = curr1->next;
            } else {
                prev->next = curr2;
                ListNode * next2 = curr2->next;
                curr2->next = curr1;
                curr2 = next2;
                curr1 = prev->next;
            }
        }
        if(!curr1) prev->next = curr2;
        if(!curr2) prev->next = curr1;
        return list1->val <= list2->val ? list1 : list2;
    }
};
