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
private:
    // BFS
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

public:
    // BFS
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root && !subRoot) return true;
        queue<TreeNode*> q {};
        q.push(root);
        while(!q.empty())
        {
            auto node = q.front();
            q.pop();
            if(!node) continue;
            if(isSameTree(node, subRoot))
            {
                return true;
            } else {
                q.push(node->left);
                q.push(node->right);
            }
        }
        return false;
    }
};
