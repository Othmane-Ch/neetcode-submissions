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
    int goodNodes(TreeNode* root) {
        if(!root) return 0;
        queue<pair<TreeNode*, int>> q {};
        q.push(make_pair(root, INT_MIN));
        int goodNodes = 0;
        while(!q.empty())
        {
            int size = q.size();
            for(int i = 0; i < size; ++i)
            {
                auto [node, max_path] = q.front();
                q.pop();
                if(!node) continue;
                if(node->val >= max_path)
                {
                    ++goodNodes;
                }
                if(node->left) q.push(make_pair(node->left, max(max_path, node->val)));
                if(node->right) q.push(make_pair(node->right, max(max_path, node->val)));
            }
        }
        return goodNodes;
    }
};
