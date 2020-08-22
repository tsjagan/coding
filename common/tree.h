#ifndef _TREE_H_
#define _TREE_H_

#include <memory>
#include <string>
#include <vector>

struct Node {
  using Ptr = std::shared_ptr<Node>;

  Node(int value) : value_(value),
                    left_(nullptr),
                    right_(nullptr) {
  }

  bool leaf() {
    return (left_ == nullptr && right_ == nullptr);
  }

  int value_;

  Node::Ptr left_;

  Node::Ptr right_;
};

class BinaryTree {
  public:
    BinaryTree() : root_(nullptr) { }

    BinaryTree(Node::Ptr node) : root_(node) { }

    Node::Ptr root() {
      return root_;
    }

    std::vector<std::vector<int>> vertical() {
      std::vector<std::vector<int>> tmp;
      int count = 0;
      auto node = root_;
      while (node != nullptr) {
        count++;
        node = node->left_;
      }
      int mid = count - 1;
      node = root_;
      while (node != nullptr) {
        count++;
        node = node->right_;
      }
      tmp.resize(count - 1, std::vector<int>());
      vertical(root_, tmp, mid);
      return tmp;
    }

    std::string inorder() {
      return inorder(root_);
    }

  private:
    void vertical(Node::Ptr node, std::vector<std::vector<int>>& res, int level) {
      if (node == nullptr) {
        return;
      }

      /* 0 1 2 3 4   
         ---------
             1
           2   3
             5   7 
       */
      res[level].push_back(node->value_);
      vertical(node->left_, res, level - 1);
      vertical(node->right_, res, level + 1);
    }

    std::string inorder(Node::Ptr node) {
      if (node == nullptr) {
        return "";
      }
      return inorder(node->left_) + ":" + std::to_string(node->value_) + ":" + inorder(node->right_);
    }

    Node::Ptr root_;
};

#endif