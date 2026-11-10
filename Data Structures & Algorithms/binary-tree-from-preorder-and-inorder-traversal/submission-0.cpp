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
private:
    TreeNode* buildSubTree(vector<int>& preorder, unordered_map<int, int>& indices,
                           int rootIdx, int start, int end)
    {
        if (end < start) return nullptr;
        int rootVal = preorder[rootIdx];
        TreeNode* root = new TreeNode(rootVal);

        int rootPos = indices[rootVal];
        int leftSize = rootPos - start;
        int start_left = start, end_left = rootPos - 1;
        int start_right = rootPos + 1, end_right = end;

        root->left  = buildSubTree(preorder, indices, rootIdx + 1, start_left, end_left);
        root->right = buildSubTree(preorder, indices, rootIdx + 1 + leftSize, start_right, end_right);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> indices;
        const int n = inorder.size();
        for (int i = 0; i < n; ++i) indices[inorder[i]] = i;
        return buildSubTree(preorder, indices, 0, 0, n - 1);
    }
};
