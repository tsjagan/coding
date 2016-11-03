/*
 * 3 bit integers
 * largest number is 0 sign bit followed by all 1's
 * smallest number is 1 sign bit then all 0's
 * 000 ---  0
 * 001 ---  1, -1 --- 111
 * 010 ---  2, -2 --- 110
 * 011 --   3, -3 --- 101
               -4 --- 100
 */

start = smallest_32bit_signed_number = (1 << 31);
end = largest_32bit_signed_number = (0x7fffffff);
bool is_bst(node*, int start, int end)
{
    - check if its in range
    - return false if not
    - ret = is_bst(node->left, start, node->data);
    - return false if ret == false
    - is_bst(node->right, node->data+1, end);
    - return false if ret == false
}

