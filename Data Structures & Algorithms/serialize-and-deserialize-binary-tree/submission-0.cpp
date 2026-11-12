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

class Codec {
private :
    int readInt(const string& data, int& i) {
        bool neg = data[i] == '-';
        if (neg) ++i;
        int val = 0;
        while (i < (int)data.size() && isdigit(data[i])) {
            val = val * 10 + (data[i] - '0'); 
            ++i;
        }
        return neg ? -val : val;
    }

public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s = "";
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty())
        {
            int size = q.size();
            string l = "[";
            for(int i = 0; i < size; ++i)
            {
                auto node = q.front(); q.pop();
                string v = node ? to_string(node->val) : "N"s;
                l += v + ",";
                if(node) q.push(node->left);
                if(node) q.push(node->right);
            }
            l.back() = ']';
            s += l;
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int i = 1;
        if(data[1] == 'N') return nullptr;
        const int n = data.size();
        auto root = new TreeNode(readInt(data, i));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            auto curr = q.front(); q.pop();
            int nodes = 0;
            ++i;
            while(i < n)
            {
                if(data[i] == '[' or data[i] == ',')
                {
                    ++i;
                    continue;
                } else if(data[i] == ']')
                {
                    break;
                } else if(data[i] == 'N') {
                    ++i;
                    if(nodes == 0) 
                    {
                        curr->left = nullptr;
                        ++nodes;
                        continue;
                    }
                    if(nodes == 1) 
                    { 
                        curr->right = nullptr;
                        break;
                    }
                } else {
                    auto node = new TreeNode(readInt(data, i));
                    q.push(node);
                    if(nodes == 0) 
                    {
                        curr->left = node;
                        ++nodes;
                        continue;
                    }
                    if(nodes == 1) 
                    { 
                        curr->right = node;
                        break;
                    }
                }
            }
        }
        return root;
    }
};
