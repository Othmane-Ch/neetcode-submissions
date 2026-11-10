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
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if(!root) return root;
        stack<TreeNode *> st {};
        stack<TreeNode *> parentStack {};
        unordered_set<TreeNode*> visited {};
        visited.insert(nullptr);
        
        st.push(root);
        parentStack.push(nullptr);
        while(!st.empty() && !parentStack.empty())
        {
            auto curr = st.top(); 
            if(curr && curr->right && !visited.contains(curr->right))
            {
                parentStack.push(curr);
                st.push(curr->right);
            } else if(curr && curr->left && !visited.contains(curr->left))
            {
                parentStack.push(curr);
                st.push(curr->left);
            } else if(curr && visited.contains(curr->left) && visited.contains(curr->right))
            {
                st.pop();
                auto parent = parentStack.top();
                parentStack.pop();
                visited.insert(curr);
                if(!curr->left && !curr->right && curr->val == target && parent)
                {
                    if(parent->right == curr) parent->right = nullptr;
                    if(parent->left == curr) parent->left = nullptr;
                    delete curr;
                }
            }
        }
        if(!root->left && !root->right && root->val == target) return nullptr;
        return root;
    }
};