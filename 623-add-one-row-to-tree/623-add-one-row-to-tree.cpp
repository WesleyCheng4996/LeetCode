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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        function(&root, val, depth, 1, false);
        return root;
    }
    void function(TreeNode** root, int val, int depth, int level, bool isright) {
        if (level == depth) {
            if(isright) {
                (*root) = new TreeNode(val, nullptr, (*root));
            } else {
                (*root) = new TreeNode(val, (*root), nullptr);
            }
        }
        if(*root == nullptr) {
            return;
        }
        function(&(*root)->left, val, depth, level + 1 ,false);
        function(&(*root)->right, val, depth, level + 1, true);
    }
};