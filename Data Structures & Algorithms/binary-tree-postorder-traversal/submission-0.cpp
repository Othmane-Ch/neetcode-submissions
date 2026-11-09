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
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root) return {};
        vector<int> res {};
        unordered_set<TreeNode *> visited {nullptr};
        stack<TreeNode*> st {};
        st.push(root);
        while(!st.empty())
        {
            auto node = st.top();
            if(node && node->right && !visited.contains(node->right))
            {
                st.push(node->right);
            }
            if(node && node->left &&!visited.contains(node->left))
            {
                st.push(node->left);
            }
            if(node && visited.contains(node->left) && visited.contains(node->right))
            {
                st.pop();
                res.push_back(node->val);
                visited.insert(node);
            }
        }
        return res;
    }
};