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
    string tree2str(TreeNode* node, string str = "") {
        str += to_string(node->val);
        if(node->left != nullptr) {
            str += '(' + tree2str(node->left) + ')';
        }
        else if(node->right != nullptr) {
            str += "()";
        }
        if(node->right != nullptr) {
            str += '(' + tree2str(node->right) + ')';
        }
        return str;
    }
};