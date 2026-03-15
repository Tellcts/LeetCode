// 二叉树的中序遍历
#pragma once

#include <vector>

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int __value) : val{__value}, left{nullptr}, right{nullptr} {}
  TreeNode() : val{0}, left{nullptr}, right{nullptr} {}
};

class Solution {
 public:
  std::vector<int> inorderTraversal(TreeNode* __root) {
    std::vector<int> ans;
    auto dfs = [&ans](auto&& __self, TreeNode* __root) {
      if (__root == nullptr) {
        return;
      }
      __self(__self, __root->left);
      ans.push_back(__root->val);
      __self(__self, __root->right);
    };
    dfs(dfs, __root);
    return ans;
  }
};