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
    string tree2str(TreeNode* root, string str = "") {
        return postOrder(root, str);
    }
    string postOrder(TreeNode* node, string& str) {
        str += to_string(node->val);
        if(node->left != nullptr) {
            str.push_back('(');
            postOrder(node->left, str);
            str.push_back(')'); 
        }
        else if(node->right != nullptr) {
            str.push_back('(');
            str.push_back(')'); 
        }
        if(node->right != nullptr) {
            str.push_back('(');
            postOrder(node->right, str);
            str.push_back(')');
        }
        return str;
    }
};