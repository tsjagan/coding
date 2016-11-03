
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

