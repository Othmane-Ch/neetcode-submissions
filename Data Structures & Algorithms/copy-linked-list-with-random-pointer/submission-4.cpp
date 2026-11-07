/*
// Definition for a Node->
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    // Time  : O(n)
    // Space : O(n)
    Node* copyRandomList(Node* head) {
        if(!head) return head;
        unordered_map<Node*, Node*> mp {};
        Node* new_head = new Node(head->val);
        mp[head] = new_head; mp[nullptr] = nullptr;
        
        Node* curr = head;
        while(curr)
        { 
            if(curr->next && !mp.contains(curr->next))
            {
                Node* new_next = new Node(curr->next->val);
                mp[curr->next] = new_next;
                mp[curr]->next = new_next;
            } else {
                mp[curr]->next = mp[curr->next];
            }
            if(curr->random && !mp.contains(curr->random))
            {
                Node* new_random = new Node(curr->random->val);
                mp[curr->random] = new_random;
                mp[curr]->random = new_random;
            }
            else
            {
                mp[curr]->random = mp[curr->random];
            }
            curr = curr->next;
        }
        return new_head;
    }
};
