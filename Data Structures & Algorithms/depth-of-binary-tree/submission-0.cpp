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
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        queue<pair<TreeNode*, int>> q {};
        q.push(make_pair(root, 1));
        int depth = 1;
        while(!q.empty())
        {
            auto [node, level] = q.front();
            depth = max(depth, level);
            q.pop();
            if(node && node->left)
            {
                q.push(make_pair(node->left, level + 1));
            }
            if(node && node->right)
            {
                q.push(make_pair(node->right, level + 1));
            }
        }
        return depth;
    }
};
