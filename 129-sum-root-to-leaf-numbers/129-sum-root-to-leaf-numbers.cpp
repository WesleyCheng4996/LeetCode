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
    int sumNumbers(TreeNode* root) {
        int sum = 0, curr = 0;
        preorder(root, sum, curr);
        return sum;
    }
    void preorder(TreeNode* root, int& sum, int& curr){
        if(root == nullptr)
            return;
        if(root->left == nullptr && root->right == nullptr){
           sum += curr * 10 + root->val;
            return;
        }
        curr = curr * 10 + root->val;
        preorder(root->left, sum, curr);
        preorder(root->right, sum, curr);
        curr -= root->val;
        curr /= 10;
    }
};