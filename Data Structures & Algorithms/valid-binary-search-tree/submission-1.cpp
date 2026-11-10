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
    bool isValidBST(TreeNode* root) {
        return valid(root, nullptr, nullptr);
    }
private:
    bool valid(TreeNode* node, TreeNode* lo, TreeNode* hi) {
        if (!node) return true;
        if (lo && node->val <= lo->val) return false;
        if (hi && node->val >= hi->val) return false;
        return valid(node->left, lo, node) && valid(node->right, node, hi);
    }
};