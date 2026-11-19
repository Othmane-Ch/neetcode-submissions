/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;
        queue<Node*> q {};
        unordered_map<Node*, Node*> copies {};
        copies[node] = new Node(node->val);
        q.push(node);
        while(!q.empty())
        {
            auto curr = q.front();q.pop();
            for(int i = 0; i < curr->neighbors.size(); ++i)
            {
                auto it = copies.find(curr->neighbors[i]);
                if(it == copies.end())
                {
                    copies[curr->neighbors[i]] = new Node(curr->neighbors[i]->val);
                    q.push(curr->neighbors[i]);
                }
                copies[curr]->neighbors.push_back(copies[curr->neighbors[i]]);
            }
        }
        return copies[node];
    }
};
