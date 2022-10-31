/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return findLCA(root, p, q);
    }
    
    TreeNode* findLCA(TreeNode* node, TreeNode* p, TreeNode* q) {
        if(node == nullptr || node == p || node == q) {
            return node;
        }
        TreeNode* left = findLCA(node->left, p, q);
        TreeNode* right = findLCA(node->right, p, q);
        if(left == nullptr) {
            return right;
        } else if(right != nullptr) {
            return node;
        } else {
            return left;
        }
        return nullptr;
    }
};

static auto s = ios_base::sync_with_stdio(false);
static auto ss = cin.tie(nullptr);
static auto sss = cout.tie(nullptr);