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
    bool isValidBST(TreeNode* root) {
        queue<tuple<TreeNode*, int, int>> q {};  
        q.push(make_tuple(root, INT_MIN, INT_MAX));
        while(!q.empty())
        {   
            auto [node, low, high] = q.front();
            q.pop();
            if(low < node->val && node->val < high)
            {
                if(node->left)
                {
                    q.push(make_tuple(node->left, low , node->val));
                }
                if(node->right)
                {
                    q.push(make_tuple(node->right, node->val, high));
                }
            } else {
                cout << node->val << endl;
                return false;
            }
        }
        return true;
    }
};
