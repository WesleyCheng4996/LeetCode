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
    int goodNodes(TreeNode* r, int ma = -10000) {
        return r ? goodNodes(r->left, max(ma, r->val)) + goodNodes(r->right, max(ma, r->val)) + (r->val >= ma) : 0;
    }
    
    void DFS(TreeNode* node,int& count, int& max) {
        if(max <= node->val) {
            ++count;
            max = node->val;
        }
        int temp;
        if(node->left != nullptr) {
            temp = max;
            DFS(node->left, count, max);
            max = temp;
        }
        if(node->right != nullptr) {
            temp = max;
            DFS(node->right, count, max);
            temp = max;
        }
    }
};