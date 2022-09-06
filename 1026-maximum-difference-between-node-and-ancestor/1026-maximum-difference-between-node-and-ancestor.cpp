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
    int maxAncestorDiff(TreeNode* root) {
        return max(DFS(root->right, root->val, root->val), DFS(root->left, root->val, root->val));
    }
    
    int DFS(TreeNode* node, int ma, int mi) {
        if(node == nullptr) {
            return ma - mi;
        }
        if(node->val > ma) {
            ma = node->val;
        }
        if(node->val < mi) {
            mi = node->val;
        }
        return max(DFS(node->left, ma, mi), DFS(node->right, ma, mi));
    }
};