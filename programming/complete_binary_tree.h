#ifndef __BINARY_TREE_H_
#define __BINARY_TREE_H_


/*
 *   1l 1R 2L 2R 3L 3R 4L
 * 1 2  3  4  5  6  7  8
 * Left  = 2P + 1 (Left is always at odd index).   P = (Left - 1)/2;
 * Right = 2P + 2 (Right is always at even index), P = (Right - 2)/2;
 */

bool is_right_child(uint32_t index)
{
    if ( index % 2 == 0 ) {
        return true;
    }
    return false;
}

bool is_left_child(uint32_t index)
{
    if ( index % 2 != 0 ) {
        return true;
    }
    return false;
}

template  <typename Tree>
int get_left_child(Tree& tree, uint32_t index, uint32_t& res)
{
    res = (2*index) + 1;
    if ( res > tree.size()-1 ) {
        return -1;
    }
    return 0;
}

template  <typename Tree>
int get_right_child(Tree& tree, uint32_t index, uint32_t& res)
{
    res = (2*index) + 2;
    if ( res > tree.size()-1 ) {
        return -1;
    }
    return 0;
}

template  <typename Tree>
int get_parent(Tree& tree, uint32_t index, uint32_t& res)
{
    // 0 is the root
    if ( index <= 0 ) {
        return -1;
    }
    if ( is_left_child(index) == true ) {
        res = (index-1)/2;
    } else {
        res = (index-2)/2;
    }
    if ( res > tree.size()-1 ) {
        return -1;
    }
    return 0;
}

template  <typename Tree>
int get_sibling(Tree& tree, uint32_t index, uint32_t& res)
{
    // root doesnt have a sibling 
    if ( index <= 0 ) {
        return -1;
    }
    if ( is_left_child(index) == true ) {
        res = (index+1);
    } else {
        res = (index-1);
    }
    if ( res > tree.size()-1 ) {
        return -1;
    }
    return 0l;
}

#endif
