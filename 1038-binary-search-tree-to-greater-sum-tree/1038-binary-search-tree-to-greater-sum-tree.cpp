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
    TreeNode* bstToGst(TreeNode* root) {
        int i = 0;
        builtGST(root, i);
        return root;
    }
    void builtGST(TreeNode* node, int& parentVal) {
        if(node == nullptr) {
            return;
        }
        builtGST(node->right, parentVal);
        parentVal = node->val += parentVal;
        builtGST(node->left, parentVal);
    }
};