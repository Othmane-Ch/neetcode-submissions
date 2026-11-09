/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    // BFS
    // Time  : O(n)
    // Space : O(n)
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<pair<TreeNode *, TreeNode*>> pending {};
        pending.push(make_pair(p, q));
        while(!pending.empty())
        {
            auto [p_node, q_node] = pending.front();
            pending.pop();
            if(!p_node && !q_node) continue;
            if(!p_node || !q_node || p_node->val != q_node->val) return false;
            pending.push(make_pair(p_node->left, q_node->left));
            pending.push(make_pair(p_node->right, q_node->right));
        }
        return true;
    }
};
