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
    // Time  : o(log(n)) or o(h) h is the height if the tree
    // Space : O(1)
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p == q) return p;
        auto curr = root;
        while(curr)
        {
            if(curr->val < q->val && curr->val < p->val)
            {
                curr = curr->right;
            } else if(curr->val > q->val && curr->val > p->val)
            {
                curr = curr->left;
            } else {
                return curr;
            }
        }
        return root;
    }
};
