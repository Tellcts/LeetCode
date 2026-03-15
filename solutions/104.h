#pragma once

#include <algorithm>

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int __value) : val{__value}, left{nullptr}, right{nullptr} {}
  TreeNode() : val{0}, left{nullptr}, right{nullptr} {}
};

class Solution {
 public:
  // 递归，自底向上
  int maxDepth_V1(TreeNode* __root) {
    if (__root == nullptr) {
      return 0;
    }
    int l_depth = maxDepth_V1(__root->left);
    int r_depth = maxDepth_V1(__root->right);
    return std::max(l_depth, r_depth) + 1;
  }

  // 递归，自顶向下
  int maxDepth_V2(TreeNode* __root) {
    int ans = 0;
    auto dfs = [&ans](auto&& __self, TreeNode* __root, int __depth) {
      if (__root == nullptr) {
        return;
      }
      ++__depth;
      ans = std::max(ans, __depth);
      __self(__self, __root->left, __depth);
      __self(__self, __root->right, __depth);
    };
    dfs(dfs, __root, 0);
    return ans;
  }
};