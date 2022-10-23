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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        creatVec(root, ret, 0);
        return ret;
    }
    void creatVec(TreeNode* root, vector<vector<int>> &vec2d, int level) {
        if(root == nullptr) {
            return;
        }
        if(vec2d.size() <= level) {
            vec2d.emplace_back();
        }
        vec2d[level].push_back(root->val);
        creatVec(root->left, vec2d, level + 1);
        creatVec(root->right, vec2d, level + 1);
    }
};