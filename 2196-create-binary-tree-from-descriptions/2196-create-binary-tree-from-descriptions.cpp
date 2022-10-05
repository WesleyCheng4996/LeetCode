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
        unordered_map<int, TreeNode*>nodes;
        unordered_set<int> root;
        unordered_set<int>son;
        nodes.reserve(descriptions.size());
        root.reserve(descriptions.size());
        son.reserve(descriptions.size());
        for (vector<int>& vec : descriptions) {
            if(nodes.count(vec[0]) == 0) {
                nodes.insert(pair<int, TreeNode*>(vec[0], new TreeNode(vec[0])));
            }
            if(nodes.count(vec[1]) == 0) {
                nodes.insert(pair<int, TreeNode*>(vec[1], new TreeNode(vec[1])));
            }
            if(vec[2]) {
                nodes[vec[0]]->left = nodes[vec[1]];
            } else {
                nodes[vec[0]]->right = nodes[vec[1]];
            }
            root.insert(vec[0]);
            son.insert(vec[1]);
        }
        
        for(int x : root) {
            if(son.count(x) == 0) {
                return nodes[x];
            }
        }
        return nullptr;
    }
};