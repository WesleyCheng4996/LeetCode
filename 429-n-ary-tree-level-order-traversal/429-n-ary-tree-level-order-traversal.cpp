/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>>ret;
        order(root, ret, 0);
        return ret;
    }
    void order(Node *node, vector<vector<int>> &vec, int level) {
        if(node == nullptr) {
            return;
        }
        if(vec.size() < level + 1) {
            vec.resize(level + 1);
        }
        vec[level].push_back(node->val);
        for(Node *x : node->children) {
            order(x, vec, level + 1);
        }
    }
};