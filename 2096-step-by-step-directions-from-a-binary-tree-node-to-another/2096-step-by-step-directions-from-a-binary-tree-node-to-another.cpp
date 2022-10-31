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
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* LCA = lowestCommonAncestor(root, startValue, destValue);
        int countU = levelDiff(LCA, startValue, 0);
        string ret(countU, 'U'), path = "";
        pathString(LCA, destValue, path);
        return ret + path;
    }
    int levelDiff(TreeNode* node, int p, int level) {
        if(node == nullptr) {
            return 0;
        }
        return node->val == p ? level : max(levelDiff(node->left, p, level + 1), levelDiff(node->right, p, level + 1));
    }
    
    bool pathString(TreeNode* root, int q, string& path) {
        if(root == nullptr) {
            return false;
        }
        if(root->val == q) {
            return true;
        }
        path.push_back('L');
        if(pathString(root->left, q, path)) {
            return true;
        } else {
            path.pop_back();
        }
        
        path.push_back('R');
        if(pathString(root->right, q, path)) {
            return true;
        } else {
            path.pop_back();
        }
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* node, int p, int q) {
        if(node == nullptr || node->val == p || node->val == q) {
            return node;
        }
        TreeNode* left = lowestCommonAncestor(node->left, p, q);
        TreeNode* right = lowestCommonAncestor(node->right, p, q);
        if(left == nullptr) {
            return right;
        } else if(right != nullptr) {
            return node;
        }
        return left;
    }
};