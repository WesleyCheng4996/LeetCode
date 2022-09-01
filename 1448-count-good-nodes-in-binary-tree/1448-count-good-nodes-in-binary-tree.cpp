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
    int goodNodes(TreeNode* root) {
        int count = 0;
        DFS(root, count, -999999);
        return count;
    }
    
    void DFS(TreeNode* node,int& count, int max) {
        if(max <= node->val) {
            ++count;
            max = node->val;
        }
        if(node->left != nullptr) {
            DFS(node->left, count, max);
        }
        if(node->right != nullptr) {
            DFS(node->right, count, max);
        }
    }
};