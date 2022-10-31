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
    int DFS(unordered_map<int, vector<int>>& edge, unordered_map<int, bool>& visited, int curr, int level) {
        int ret = level;
        visited[curr] = true;
        for(int x : edge[curr]) {
            if(!visited[x]) {
                ret = max(ret, DFS(edge, visited, x, level + 1));
            }
        }
        return ret;
    }
        
    void builtGraph(TreeNode* node, unordered_map<int, vector<int>>& edge) {
        if(node->left != nullptr) {
            edge[node->val].push_back(node->left->val);
            edge[node->left->val].push_back(node->val);
            builtGraph(node->left, edge);
        }
        if(node->right != nullptr) {
            edge[node->val].push_back(node->right->val);
            edge[node->right->val].push_back(node->val);
            builtGraph(node->right, edge);
        }
    }
    
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int, vector<int>>edge;
        builtGraph(root, edge);
        unordered_map<int, bool>visited(edge.size());
        return DFS(edge, visited, start, 0);
    }
};