#include<iostream>
#include<vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* Helper(vector<int>& nums, int start, int end){
    int size = end - start;
    int index;
    TreeNode* node = nullptr;
    if (size > 3){
        index = size / 2 + start;
        node = new TreeNode(nums[index], Helper(nums, start, index), Helper(nums, index + 1, end));
        return node;
    } else if (size == 3){
        TreeNode* node1 = new TreeNode(nums[start]);
        TreeNode* node2 = new TreeNode(nums[start + 2]);
        node = new TreeNode(nums[start + 1], node1, node2);
    } else if (size == 2){
        TreeNode* node1 = new TreeNode(nums[start]);
        node = new TreeNode(nums[start + 1], node1, nullptr);
    } else if (size == 1){
        node = new TreeNode(nums[start], nullptr, nullptr);
    }
    return node;
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
    int n = nums.size();
    return Helper(nums, 0, n);
}

int main() {

    vector<int> vec = {0,1,2,3,4,5,6,7,8};
    auto node = sortedArrayToBST(vec);
    cout << "ok" << endl;

    return 0;
}