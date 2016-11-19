/*
  Given a complete binary tree with nodes of values of either 1 or 0, the following rules always hold:
    (1) a node's value is 1 if and only if all its subtree nodes' values are 1
    (2) a leaf node can have value either 1 or 0
    Implement the following 2 APIs:
    set_bit(offset, length), set the bits at range from offset to offset+length-1
    clear_bit(offset, length), clear the bits at range from offset to offset+length-1

    i.e. The tree is like:
                 0
              / \
             0 1
           / \ / \
          1 0 1 1
         /\ / \ /
        1 1 1 0 1
        Since it's complete binary tree, the nodes can be stored in an array:
        [0,0,1,1,0,1,1,1,1,1,0,1]
*/
#include <stdlib.h>
#include <iostream>
#include <stdint.h>
#include <string>

#include "complete_binary_tree.h"

using namespace std;
using Tree = std::string;

void _propagate(Tree& tree, uint32_t index)
{
    uint32_t parent = index;
    while ( true ) {
        uint32_t sibling = -1, parent = 0;
        char bit = '0';
        int ret = get_sibling<Tree>(tree, index, sibling);
        if ( ret == -1 && index < tree.size()-1 ) {
            break;
        }
        if ( index == tree.size()-1 ) {
            sibling = index;
        }
        if ( tree[sibling] == '1' and tree[index] == '1') {
            bit = '1';
        }
        ret = get_parent<Tree>(tree, index, parent);
        if ( ret == -1 ) {
            break;
        }
        tree[parent] = bit;
        index = parent;
    }
}

int set_bit(Tree& tree, uint32_t offset, uint32_t length, char bit='1')
{
    uint32_t end = offset + length - 1;
    if ( end > tree.size()-1 ) {
        return -1;
    }
    if ( is_right_child(offset) == true ) {
        tree[offset] = bit;
        _propagate(tree, offset);
        offset++;
    }
    while ( offset <= end ) {
        tree[offset] = bit;
        if ( offset+1 <= end ) {
            tree[offset+1] = bit;
        }
        _propagate(tree, offset);
        offset += 2;
    }
    return 0;
}

int clear_bit(Tree& tree, uint32_t offset, uint32_t length)
{
    return set_bit(tree, offset, length, '0');
}

int main(void)
{
    Tree tree;
    cout << "Enter the tree bits : ";
    cin >> tree;
    
    set_bit(tree, tree.size()-1, 1);
    cout << "Tree is : " << tree << endl;

    clear_bit(tree, tree.size()-1, 1);
    cout << "Tree is : " << tree << endl;

    set_bit(tree, tree.size()-2, 2);
    cout << "Tree is : " << tree << endl;

    return 0;
}
