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
    // DFS
    // Time  : O(n)
    // Space : O(n)
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        stack<pair<TreeNode *, int>> st {};
        st.push(make_pair(root, 1));
        int depth = 1;
        while(!st.empty())
        {
            auto [node, level] = st.top();
            st.pop();
            depth = max(depth, level);
            if(node && node->right)
            {
                st.push(make_pair(node->right, level + 1));
            }
            if(node && node->left)
            {
                st.push(make_pair(node->left, level + 1));
            }
        }
        return depth;
    }
};
