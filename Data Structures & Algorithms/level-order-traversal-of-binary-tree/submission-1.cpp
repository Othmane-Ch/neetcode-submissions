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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result {};
        if(!root) return result;
        queue<TreeNode *> q {};
        q.push(root);
        while(!q.empty())
        {
            int size = q.size(); 
            vector<int> traversal(size, 0);
            for(int i = 0; i < size; ++i)
            {
                auto node = q.front();
                q.pop();
                traversal[i] = node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            result.push_back(traversal);
        }
        return result;
    }
};
