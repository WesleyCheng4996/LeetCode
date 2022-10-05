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

TreeNode buffer[20001];
// 1081: memset
// 1034: placement new

class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& desc) { // 1079
        vector<pair<int,int>> data;
        data.reserve(desc.size());
        for (auto &v: desc) {
            int parent = v[0];
            int child = v[1];
            bool isleft = v[2];
            data.emplace_back(parent, child*2+isleft);
        }
        sort(data.begin(), data.end());
        // sort(desc.begin(), desc.end(), [](vector<int> const& a, vector<int> const& b) {
        //     return a[0] < b[0] || (a[0] == b[0] && a[1] < b[1]);
        // });
        TreeNode* buf = &buffer[0];
        TreeNode* nodes[100001] = {};
        vector<bool> ischild(100001);
        int max_val = 0;
        for (auto [parent, child]: data) {
            bool isleft = child & 1;
            child >>= 1;
            
            TreeNode* pnode = nodes[parent];
            if (!pnode) pnode = nodes[parent] = new (buf++) TreeNode(parent);
            TreeNode* cnode = nodes[child];
            if (!cnode) cnode = nodes[child] = new (buf++) TreeNode(child);
            
            if (isleft) {
                pnode->left = cnode;
            } else {
                pnode->right = cnode;
            }
            ischild[child] = true;
            max_val = max({max_val, parent, child});
        }
        for (int i = 0; i <= max_val; ++i) {
            if (nodes[i] && !ischild[i]) return nodes[i];
        }
        __builtin_unreachable();
    }
    
    TreeNode* createBinaryTree1079(vector<vector<int>>& desc) {
        TreeNode* nodes[100001] = {};
        short indegrees[100001] = {};
        int max_val = 0;
        for (auto &v: desc) {
            int parent = v[0];
            int child = v[1];
            bool isleft = v[2];
            
            TreeNode* pnode = nodes[parent];
            if (!pnode) pnode = nodes[parent] = new TreeNode(parent);
            TreeNode* cnode = nodes[child];
            if (!cnode) cnode = nodes[child] = new TreeNode(child);
            
            if (isleft) {
                pnode->left = cnode;
            } else {
                pnode->right = cnode;
            }
            ++indegrees[child];
            max_val = max({max_val, parent, child});
        }
        for (int i = 0; i <= max_val; ++i) {
            if (nodes[i] && indegrees[i] == 0) return nodes[i];
        }
        __builtin_unreachable();
    }
    
    TreeNode* createBinaryTree_contest(vector<vector<int>>& desc) {
        map<int,TreeNode*> nodes;
        set<int> children, parents;
        for (auto &v: desc) {
            int parent = v[0];
            int child = v[1];
            bool isleft = v[2];
            if (!nodes[parent]) nodes[parent] = new TreeNode(parent);
            if (!nodes[child]) nodes[child] = new TreeNode(child);
            if (isleft) {
                nodes[parent]->left = nodes[child];
            } else {
                nodes[parent]->right = nodes[child];
            }
            parents.insert(parent);
            children.insert(child);
        }
        for (int p: parents) {
            if (children.count(p) == 0) return nodes[p];
        }
        return nullptr;
    }
};