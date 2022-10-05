#include<iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool Helper(TreeNode* node, int target, int sum){
    if (node == nullptr){
        return false;
    }
    sum += node->val;
    if (node->left == nullptr && node->right == nullptr){
        if (target == sum){
            return true;
        }
    } else {
        if (Helper(node->right, target, sum) || Helper(node->left, target, sum)){
            return true;
        } else {
            return false;
        }
    }
    return false;
}

bool hasPathSum(TreeNode* root, int targetSum) {
    int sum = 0;
    return Helper(root, targetSum, sum);
}

int main() {

    TreeNode t1(1);
    TreeNode t2(2);

    TreeNode t3(3, &t1, &t2);

    cout << hasPathSum(&t3, 4);

    return 0;
}

