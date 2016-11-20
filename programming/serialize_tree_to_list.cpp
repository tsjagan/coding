#include <stdlib.h>
#include <string>
#include <vector>
#include <iostream>
#include <memory>

#include "BST.h"
#include "linked_list.h"

using namespace std;

ll::SinglyLinkedList::Ptr serialize_to_list(bst::BST::Ptr tree)
{
  if ( tree->root() == nullptr ) {
    return (nullptr);
  }
  ll::SinglyLinkedList::Ptr list = std::make_shared<ll::SinglyLinkedList>(tree->root()->value_);
  return _serialize_to_list(tree->root(), list->head())
}
/*
1) If its a BST, the  Preorder/Postorder is enough (ambigious though)
min--max range approach

2) Complete binary Tree: (all nodes except the last are completely filled,
and last level nodes are as left as possible)
        5
     3     7
  2  4   6  9
1  0
In this case, level order traversal is enough
Lever order traversal: 5-3-7-2-4-6-9-1-0-
Use a queue to serialize and deserialize

3) Full binary tree: (all internal nodes have 2 children)
        5
     3     7
  2  4   6  9
In this case:
Preorder: 5-3-2-4-7-6-9- with null markers is enough
This method can be used for (2) as well

4) For just an arbitrary regular binary tree, we need inorder and preorder
For binary tree: (need 2 traversals)
Preorder:
5-1-2-3-7-6-9-
Inorder:
2-1-3-5-6-7-9-
*/

void _serialize_to_list(bst::Node::Ptr tree_node, ll::Node::Ptr list_node)
{
    if ( tree_node == nullptr ) {
      return;
    }
    return l;
}
bst::BST::Ptr build_tree()
{
  bst::BST::Ptr b = std::make_shared<bst::BST>();
  while ( true ) {
    int value = 0;
    cout << "Enter value : ";
    cin >> value;
    if ( value == -1000 ) {
      break;
    }
    bst::Node::Ptr n = std::make_shared<bst::Node>(value);
    b->insert(n);
  }
  return b;
}

int main(void)
{
  auto b = build_tree();
  cout << b->inorder() << endl;
  cout << b->sorted() << endl;
  return 0;
}
