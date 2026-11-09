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
    int dfs(TreeNode * root)
    {
        if(!root) return 0;
        int leftHeight = dfs(root->left);
        int rightHeight = dfs(root->right);
        return 1 + max(leftHeight, rightHeight);
    }
public:
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        return abs(dfs(root->right) - dfs(root->left)) <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }
};
