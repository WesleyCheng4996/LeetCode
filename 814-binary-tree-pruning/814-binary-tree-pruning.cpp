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
    TreeNode* pruneTree(TreeNode*& root) {
        preOrder(root);
        return root;
    }
    bool preOrder(TreeNode*& node) {
        
        if(node == nullptr) {
            return false;
        }
        
        if(node->val | preOrder(node->left) | preOrder(node->right)) {
            return true;
        }
        
        node = nullptr;
        return false;
    }
};