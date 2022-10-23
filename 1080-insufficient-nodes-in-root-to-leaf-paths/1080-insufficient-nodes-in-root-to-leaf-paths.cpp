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
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        dfs(&root, limit, 0);
        return root;
    }
    bool dfs(TreeNode** root, int limit, int sum) {
        if((*root)->left == nullptr && (*root)->right == nullptr) {
            if(sum + (*root)->val < limit) {
                *root = nullptr;
            }
            return *root == nullptr;
        }
        bool k = true;
        if((*root)->left != nullptr) {
            k = dfs(&(*root)->left, limit, sum + (*root)->val);
        }
        if((*root)->right != nullptr) {
            k &= dfs(&(*root)->right, limit, sum + (*root)->val);
        }
        if(k) {
            *root = nullptr;
        }
        return k;
    }
};