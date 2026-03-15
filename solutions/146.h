// LRU缓存
#pragma once

#include <unordered_map>

// 双向链表节点
struct Node {
  int key;
  int value;
  Node* prev;
  Node* next;

  Node() : key{0}, value{0}, prev{nullptr}, next{nullptr} {}
  Node(int __key, int __value)
      : key{__key}, value{__value}, prev{nullptr}, next{nullptr} {}
};

class LRUCache {
 private:
  int capacity_;
  Node* guard_;
  std::unordered_map<int, Node*> key_to_node_;

  // 删除节点
  void remove(Node* __node) {
    __node->prev->next = __node->next;
    __node->next->prev = __node->prev;
  }

  // 将节点移到LRU链表的头部
  void push_front(Node* __node) {
    __node->prev = guard_;
    __node->next = guard_->next;
    __node->prev->next = __node;
    __node->next->prev = __node;
  }

  // 获取节点指针并将其放到LRU链表头部
  Node* get_node(int __key) {
    auto it = key_to_node_.find(__key);
    if (it == key_to_node_.end()) {
      return nullptr;
    }
    Node* node = it->second;
    remove(node);
    push_front(node);
    return node;
  }

 public:
  explicit LRUCache(int __capacity)
      : capacity_{__capacity}, guard_{new Node()} {
    guard_->next = guard_;
    guard_->prev = guard_;
  }

  int get(int __key) {
    Node* node = get_node(__key);
    return node ? node->value : -1;
  }

  void put(int __key, int __value) {
    Node* node = get_node(__key);
    if (node) {
      node->value = __value;
      return;
    }
    key_to_node_[__key] = node = new Node(__key, __value);
    push_front(node);
    if (key_to_node_.size() > capacity_) {
      Node* back_node = guard_->prev;
      key_to_node_.erase(back_node->key);
      remove(back_node);
      delete back_node;
    }
  }
};