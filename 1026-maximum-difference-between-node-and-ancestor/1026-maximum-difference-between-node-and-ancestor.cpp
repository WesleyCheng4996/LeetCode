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
    int maxAncestorDiff(TreeNode* root, int ma = -99999, int mi = 999999) {
        if(root == nullptr) {
            return ma - mi;
        }
        if(root->val > ma) {
            ma = root->val;
        }
        if(root->val < mi) {
            mi = root->val;
        }
        return max(maxAncestorDiff(root->left, ma, mi), maxAncestorDiff(root->right, ma, mi));
    }
};