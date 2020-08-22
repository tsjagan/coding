
#include <iostream>
#include <algorithm>
#include <vector>
#include "utils.h"
#include "timer.h"
#include "utils.h"
#include "tree.h"

using namespace std;

int main(void) {
  Node::Ptr root = make_shared<Node>(3);
  root->left_ = make_shared<Node>(9);
  root->right_ = make_shared<Node>(20);
  root->left_->left_  = make_shared<Node>(5);
  root->right_->left_  = make_shared<Node>(15);
  root->right_->right_ = make_shared<Node>(7);

  BinaryTree tree(root);

  cout << tree.inorder() << endl;

  auto res = tree.vertical();
  for (auto& r : res) {
    cout << ":";
    print(r);
  }

  return 0;
}