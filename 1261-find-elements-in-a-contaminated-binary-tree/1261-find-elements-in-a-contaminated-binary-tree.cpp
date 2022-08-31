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
class FindElements {
public:
    FindElements(TreeNode* root) {
        if(root == nullptr) {
            return;
        }
        Recursive(root, 0);
    }
    void Recursive(TreeNode* root, int curr) {
        s.insert(curr);
        if(root->left != nullptr) {
            Recursive(root->left, (curr << 1) + 1);
        }
        if(root->right != nullptr) {
            Recursive(root->right, (curr << 1) + 2);
        }
    }
    bool find(int target) {
        return s.count(target);
    }
    set<int> s;
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */