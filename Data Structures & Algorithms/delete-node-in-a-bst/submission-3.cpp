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
    // Time  : O(h)
    // Space : O(1)
    TreeNode* deleteNode(TreeNode* root, int key) {
        auto curr = root;
        TreeNode * parent {};
        while(curr)
        {
            if(curr->val < key)
            {
                parent = curr;
                curr = curr->right;
            } else if(curr->val > key)
            {
                parent = curr;
                curr = curr->left;
            } else {
                TreeNode* replacement = curr->left;
                if (curr->right) {
                    replacement = curr->right;
                    auto succ = replacement;
                    while (succ->left) succ = succ->left;
                    succ->left = curr->left;
                }
                if (!parent)                  root = replacement;
                else if (parent->left == curr) parent->left = replacement;
                else                           parent->right = replacement;
                delete curr;
                break;
            }
        }
        return root;
    }
};