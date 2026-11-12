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
    int maxPathSum(TreeNode* root) {
        stack<TreeNode *> post_order {};
        stack<TreeNode *> st {};
        st.push(root);
        while(!st.empty())
        {
            auto node = st.top(); st.pop();
            post_order.push(node);
            if(node->left) st.push(node->left);
            if(node->right) st.push(node->right);
        }
        
        unordered_map<TreeNode*, int> gain {};
        gain[nullptr] = 0;
        int max_path = INT_MIN;
        while(!post_order.empty())
        {
            auto node = post_order.top(); post_order.pop();
            int l = max(0, gain[node->left]);    // parent decides to skip a bad child
            int r = max(0, gain[node->right]);
            max_path = max(max_path, node->val + l + r);   // path peaking here
            gain[node] = node->val + max(l, r);            // chain starting here
        }
        return max_path;
    }
};
