#ifndef __LINKED_LIST_H_
#define __LINKED_LIST_H_

#include <stdlib.h>
#include <string>
#include <memory>

using namespace std;

namespace ll {

struct Node {
  using Ptr = std::shared_ptr<Node>;
  Node(int value) :
       value_(value),
       next_(nullptr) { }
  int value_;
  Node::Ptr next_;
};

class LinkedList {
public:
  using Ptr = std::shared_ptr<LinkedList>;
  LinkedList() : head_(nullptr) { }
  LinkedList(Node::Ptr n) : head_(n), curr_(nullptr) { }
  int add(Node::Ptr n) {
    if ( head_ == nullptr ) {
      head_ = n;
      curr_ = head_;
      return 0;
    }
    curr_->next = n;
    curr_ = curr->next_;
    return 0;
  }
  Node::Ptr head() {
    return head_;
  }
  std::string print() {
    std::string res;
    auto n = head_;
    while ( n != nullptr ) {
      res += to_string(n->value_) + "-";
      n = n->next_;
    }
    return res;
  }
private:
  Node::Ptr head_;
  Node::Ptr curr_;
};

}
#endif
