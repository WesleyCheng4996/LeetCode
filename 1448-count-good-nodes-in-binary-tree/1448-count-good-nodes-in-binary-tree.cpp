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
        if(root == nullptr) {
            return 0;
        }
        int count = 0;
        DFS(root, count, root->val);
        return count;
    }
    
    void DFS(TreeNode* node,int& count, int& max) {
        if(max <= node->val) {
            ++count;
            max = node->val;
        }
        if(node->left != nullptr) {
            int temp = max;
            DFS(node->left, count, max);
            max = temp;
        }
        if(node->right != nullptr) {
            int temp = max;
            DFS(node->right, count, max);
            temp = max;
        }
    }
};