#include <vector>
#include <unordered_map>

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void Helper(TreeNode* node, int trgt, TreeNode* parent, unordered_map<TreeNode*, TreeNode*>& ch_p, vector<TreeNode*>& nodes){
    ch_p[node] = parent;
    trgt -= node->val;
    if (node->left != nullptr){
        Helper(node->left, trgt, node, ch_p, nodes);
        if (node->right != nullptr){
            Helper(node->right, trgt, node, ch_p, nodes);
        }
    } else {
        if (node->right == nullptr){
            if (trgt == 0){
                nodes.push_back(node);
            }
        } else {
            Helper(node->right, trgt, node, ch_p, nodes);
        }
    }
}

void Helper2(vector<TreeNode*> nodes, unordered_map<TreeNode*, TreeNode*>& ch_p, vector<vector<int>>& result){
    for (auto node : nodes){
        vector<int> path;
        while (node != nullptr) {
            path.push_back(node->val);
            node = ch_p[node];
        }
        reverse(path.begin(), path.end());
        result.push_back(path);
    }
}

vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    vector<vector<int>> result;
    vector<TreeNode*> nodes;
    unordered_map<TreeNode*, TreeNode*> child_parent;
    if (root != nullptr){
        Helper(root, targetSum, nullptr, child_parent, nodes);
    }
    Helper2(nodes, child_parent, result);
    return result;
}

int main() {



    return 0;
}