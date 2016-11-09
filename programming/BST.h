#ifndef __BST_H_
#define __BST_H_

#include <stdlib.h>
#include <string>
#include <vector>
#include <iostream>
#include <memory>

using namespace std;

namespace bst {

struct Node {
  using Ptr = std::shared_ptr<Node>;
  Node(int value) :
      value_(value),
      left_(nullptr),
      right_(nullptr) { }
  bool leaf() {
    if ( left_ == nullptr and right_ == nullptr ) {
      return true;
    }
    return false;
  }
  int value_;
  Node::Ptr left_;
  Node::Ptr right_;
};

class BST {
public:
  using Ptr = std::shared_ptr<BST>;
  BST() : root_(nullptr) { }
  BST(Node::Ptr root) : root_(root) { }
  int insert(Node::Ptr node) {
      if ( root_ == nullptr ) {
        root_ = node;
        return 0;
      }
      auto curr = root_;
      Node::Ptr add = curr;
      while ( curr != nullptr ) {
        if ( node->value_ <= curr->value_ ) {
            add = curr;
            curr = curr->left_;
        } else {
            add = curr;
            curr = curr->right_;
        }
      }
      if ( node->value_ <= add->value_ ) {
        add->left_ = node;
      } else {
        add->right_ = node;
      }
      return 0;
  }
  Node::Ptr root() {
    return root_;
  }
  std::string inorder() {
    std::string res;
    _inorder(root_, res);
    return res;
  }
  void _inorder(Node::Ptr n, string& res) {
    if ( n == nullptr ) {
      return;
    }
    res += to_string(n->value_) + "-";
    _inorder(n->left_, res);
    _inorder(n->right_, res);
  }
  std::string sorted() {
    std::string res;
    _preorder(root_, res);
    return res;
  }
  void _preorder(Node::Ptr n, string& res) {
    if ( n == nullptr ) {
      return;
    }
    _inorder(n->left_, res);
    res += to_string(n->value_) + "-";
    _inorder(n->right_, res);
  }
private:
  Node::Ptr root_;
};

}
#endif
