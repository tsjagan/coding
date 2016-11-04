#ifndef __BINARY_TREE_H_
#define __BINARY_TREE_H_

/*
 *   1l 1R 2L 2R 3L 3R 4L
 * 1 2  3  4  5  6  7  8
 * Left  = 2P + 1 (Left is always at odd index).   P = (Left - 1)/2;
 * Right = 2P + 2 (Right is always at even index), P = (Right - 2)/2;
 */
int get_left_child(Tree& tree, uint32_t index, uint32_t& res)
{
    res = (2*index) + 1;
    if ( res > tree.size()-1 ) {
        return -1;
    }
    return 0;
}

int get_right_child(Tree& tree, uint32_t index, uint32_t& res)
{
    res = (2*index) + 2;
    if ( res > tree.size()-1 ) {
        return -1;
    }
    return 0;
}

int get_parent(Tree& tree, uint32_t index, uint32_t& res)
{
    if ( is_left_child(tree, index) == true ) {
        return (index-1)/2;
    }
    return (index-2)/2;
}

int get_sibling(Tree& uint32_t index, uint32_t& res)
{
    if ( is_left_child(tree, index) == true ) {
        return (index+1);
    }
    return (index-1);
}

bool is_right_child(Tree& tree, uint32_t index)
{
    if ( index % 2 == 0 ) {
        return true;
    }
    return false;
}

bool is_left_child(Tree& tree, uint32_t index)
{
    if ( index % 2 != 0 ) {
        return true;
    }
    return false;
}

#endif
