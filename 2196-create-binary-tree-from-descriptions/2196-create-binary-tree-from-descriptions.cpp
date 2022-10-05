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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, int[2]>nodes;
        unordered_map<int, bool>ishead;
        int head;
        for (vector<int>& vec : descriptions) {
            nodes[vec[0]][vec[2]] = vec[1];
            if(ishead.count(vec[0]) == 0) {
                ishead[vec[0]] = true;
            }
            ishead[vec[1]] = false;
        }
        for(auto& [val, b] : ishead) {
            if(b) {
                head = val;
                break;
            }
        }
        return creatNode(new TreeNode(head), nodes);;
    }
    
    TreeNode* creatNode(TreeNode* root, unordered_map<int, int[2]>& mp) {
        if(mp[root->val][0]) {
            root->right = new TreeNode(mp[root->val][0]);
            creatNode(root->right, mp);
        }
        if(mp[root->val][1]) {
            root->left = new TreeNode(mp[root->val][1]);
            creatNode(root->left, mp);
        }
        return root;
    }
    
};