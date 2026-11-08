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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        const int k = lists.size();
        if(k == 0) return nullptr;
        priority_queue<int, vector<int>, greater<int>> min_heap {};
        for(int i=0; i < k; ++i)
        {
            auto * head = lists[i];
            while(head)
            {
                min_heap.push(head->val);
                auto next = head->next;
                head = next;
            }
        }
        ListNode dummy(0, nullptr);
        auto curr = &dummy;
        while(!min_heap.empty())
        {
            int val = min_heap.top();
            min_heap.pop();
            auto node = new ListNode(val);
            curr->next = node;
            curr = node;
        }
        return dummy.next;
    }
};
