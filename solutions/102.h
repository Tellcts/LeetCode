// 二叉树的层序遍历
#pragma once

#include <queue>
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
  // 两个数组
  std::vector<std::vector<int>> levelOrder_V1(TreeNode* __root) {
    if (__root == nullptr) {
      return {};
    }
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

  // 一个队列
  std::vector<std::vector<int>> levelOrder_V2(TreeNode* __root) {
    if (__root == nullptr) {
      return {};
    }
    std::vector<std::vector<int>> ans;
    std::queue<TreeNode*> q;
    q.push(__root);
    while (!q.empty()) {
      std::vector<int> vals;
      for (int n = q.size(); n--;) {
        TreeNode* node = q.front();
        q.pop();
        vals.push_back(node->val);
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
      }
      ans.push_back(std::move(vals));
    }
    return ans;
  }
};