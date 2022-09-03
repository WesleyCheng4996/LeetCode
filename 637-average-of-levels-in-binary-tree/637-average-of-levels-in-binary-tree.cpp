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
    vector<double> averageOfLevels(TreeNode* root) {
        unordered_map<int, vector<int>>map;
        vector<double> average;
        DFS(root, 0, map);
        average.resize(map.size());
        for(auto x : map) {
            for(auto y : x.second) {
                average[x.first] += y;
            }
            average[x.first] /= x.second.size();
        }
        return average;
    }
    
    void DFS(TreeNode* root, int level, unordered_map<int, vector<int>>& map) {
        map[level].push_back(root->val);
        if(root->left != nullptr) {
            DFS(root->left, level + 1, map);
        } 
        if(root->right != nullptr) {
            DFS(root->right, level + 1, map);
        } 
    }
    
};