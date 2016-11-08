/*
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.
Return a deep copy of the list.
*/
/*
1-2-3-4-5--
1**3
2**null
3**1
4**5
5**2
*/

Naive:
- map from  [old_this->random] -> [new_this]
- when we create new_this, check map for old_this.
  If exists then map[old_this]->random = new_this

Node* deep_copy_with_random_ptr(Node* head)
{
  std::map<Node*, Node*> c;
  Node *curr = head, *newhead = nullptr;
  while ( curr != nullptr ) {
    Node *newnode = create_node(curr);
    c[curr->random] = newnode;
    if ( exists(c[curr]) == true ) {
      c[curr]->random = newnode;
    }
    if ( curr == head ) {
      newhead = curr;
    }
  }
  return newhead;
}

int main(void)
{
  return 0;
}
