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
    TreeNode* pruneTree(TreeNode* root) {
        preOrder(root);
        return root;
    }
    bool preOrder(TreeNode*& node) {
        bool record = node->val;
        if(node->left != nullptr) {
            record |= preOrder(node->left);
        }
        if(node->right != nullptr) {
            record |= preOrder(node->right);
        }
        if(record == true) {
            return true;
        }
        delete node;
        node = nullptr;
        return false;
    }
};