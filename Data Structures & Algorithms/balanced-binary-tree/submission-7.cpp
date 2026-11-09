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
    // Time  : O(n)
    // Space : O(n)
    bool isBalanced(TreeNode* root) {
        unordered_map<TreeNode*, int> heights {};
        heights[nullptr] = 0;
        stack<TreeNode *> st {};
        st.push(root);
        while(!st.empty())
        {
            auto node = st.top();
            if(!node){
                st.pop();
                continue;
            }
            if(heights.contains(node->right) && heights.contains(node->left))
            {
                st.pop();
                if(abs(heights[node->right] - heights[node->left]) > 1) return false;
                heights[node] = 1 + max(heights[node->right], heights[node->left]);
            }
            if(!heights.contains(node->left))
            {
                st.push(node->left);
            }
            if(!heights.contains(node->right))
            {
                st.push(node->right);
            }
        }
        return true;
    }
};
