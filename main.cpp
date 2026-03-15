#include <iostream>

struct BiTreeNode {
  int value;
  BiTreeNode* left;
  BiTreeNode* right;
  BiTreeNode(int __value) : value{__value}, left{nullptr}, right{nullptr} {}
};

void midOrder(BiTreeNode* __root) {
  if (__root == nullptr) {
    return;
  }
  midOrder(__root->left);
  std::cout << __root->value << " ";
  midOrder(__root->right);
}
int main() {
  auto node1 = new BiTreeNode(1);
  node1->left = new BiTreeNode(2);
  node1->right = new BiTreeNode(3);
  midOrder(node1);
  return 0;
}