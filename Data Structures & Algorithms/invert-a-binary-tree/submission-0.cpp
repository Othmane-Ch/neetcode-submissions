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
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return root;
        queue<TreeNode *> q {};
        q.push(root);
        while(!q.empty())
        {
            auto node = q.front();
            q.pop();
            if(node && node->left)
            {
                q.push(node->left);
            }
            if(node && node->right)
            {
                q.push(node->right);
            }
            swap(node->left, node->right);
        }
        return root;
        
    }
};
