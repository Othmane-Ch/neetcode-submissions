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
    TreeNode* deleteNode(TreeNode* root, int key) {
        auto curr = root;
        TreeNode * parent {};
        while(curr)
        {
            if(curr->val < key)
            {
                parent = curr;
                curr = curr->right;
            } else if(curr->val > key)
            {
                parent = curr;
                curr = curr->left;
            } else{
                if(parent)
                {
                    if(!curr->right && !curr->left)
                    {
                        if(curr->val < parent->val) parent->left = nullptr; 
                        if(curr->val > parent->val) parent->right = nullptr;
                        delete curr;
                    } else if(curr->right)
                    {
                        auto leftNode = curr->left;
                        auto rightNode = curr->right;
                        if(curr->val < parent->val) parent->left = rightNode;
                        if(curr->val > parent->val) parent->right = rightNode;
                        delete curr;
                        curr = rightNode;
                        while(curr->left)
                        {
                            curr = curr->left;
                        }
                        curr->left = leftNode;
                    } else {
                        auto leftNode = curr->left;
                        if(curr->val < parent->val) parent->left = leftNode;
                        if(curr->val > parent->val) parent->right = leftNode;
                        delete curr;
                    }
                } else {
                    auto leftNode = root->left;
                    auto rightNode = root->right;
                    delete root;
                    if(rightNode)
                    {
                        root = rightNode;
                        curr = root;
                        while(curr->left)
                        {
                            curr = curr->left;
                        }
                        curr->left = leftNode;
                    } else {
                        root = leftNode;
                    }
                }
                break;
            }
        }
        return root;
    }
};