// 二叉树的层序遍历
#pragma once

#include <utility>
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
  std::vector<std::vector<int>> levelOrder(TreeNode* __root) {
    std::vector<std::vector<int>> ans;
    std::vector<TreeNode*> cur{__root};
    while (cur.size()) {
      std::vector<TreeNode*> nxt;
      std::vector<int> vals;
      for (const auto& node : cur) {
        vals.push_back(node->val);
        if (node->left) nxt.push_back(node->left);
        if (node->right) nxt.push_back(node->right);
      }
      cur = std::move(nxt);
      ans.push_back(std::move(vals));
    }
    return ans;
  }
};