

node* rebuild_tree(preorder, inorder, preoff, instart, inend)
{
  if ( preoff >= preorder.size() ) {
    return nullptr;
  }
  newnode = create_node(preorder[preoff]);
  inoff = lookup(preorder[preoff], inorder, instart, inend);

  preoff++;
  newnode->left = rebuild_tree(preorder, inorder, preoff, instart, inoff-1);
  newnode->right = rebuild_tree(preorder, inorder, preoff, inoff+1, inend);
  return newnode;
}
/*
     5
  3     7
2  4   6  9
*/
inorder_no_recursion(node* root)
{
  if ( n == nullptr ) {
    return;
  }
  node *curr = root;
  while ( curr != nullptr ) {
    if ( curr->left != nullptr ) {
      node *tmp = curr;
      // build bridge to come back to this;
      tmp = tmp->left;
      while ( tmp->right != nulltr ) {
        if ( tmp->right == curr ) {
          print tmp->right;
          curr = tmp->right;
          tmp->right = nullptr;
          up = true;
        } else {
          tmp = tmp->right;
        }
      }
      if ( up == false ) {
        tmp->right = curr;
        curr = curr->left;
      }
    }
  } else {
    print curr
    curr = curr->right;
  }

}
