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
    // Recursive
    // Time  : O(n)
    // Space : O(n)
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        auto dfs = [&](this auto&& self, TreeNode* node) -> int {
            if(!node) return 0;
            int leftHeight = self(node->left);
            int rightHeight = self(node->right);
            diameter = max(diameter, leftHeight + rightHeight);
            return 1 + max(leftHeight, rightHeight);
        };
        dfs(root);
        return diameter;
    }
};
