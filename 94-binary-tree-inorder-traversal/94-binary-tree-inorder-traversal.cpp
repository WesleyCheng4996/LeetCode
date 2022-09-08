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
    vector<int> inorderTraversal(TreeNode* root) {
        if(root == nullptr) {
            return vector<int>();
        }
        vector<int> vec;
        return inorder(root, vec);
    }
    vector<int> inorder(TreeNode* node, vector<int>& vec) {
        if(node->left != nullptr) {
            inorder(node->left, vec);
        }
        vec.push_back(node->val);
        if(node->right != nullptr) {
            inorder(node->right, vec);
        }
        return vec;
    }
};