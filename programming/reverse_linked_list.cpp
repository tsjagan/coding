
// 1 2 3 4 
// 2 1 3 4 
// 3 2 1 4 
// 4 3 2 1 
Node* reverse_list(Node* head)
{
    if ( head == nullptr ) {
        return nullptr;
    }
    Node *prev = head;
    Node *curr = head->next;
    while ( curr != nullptr ) {
        prev->next = curr->next;
        curr->next = head;;
        head = curr;
        curr = prev->next;
    }
    return head;
}

//   p c l
// 1 2 3 4
// p c   l
// 1 2 4 3
// c     l p=null
// 1 4 3 2
// 4 3 2 1
Node* recursive_reverse_list(Node* head)
{
    if ( head == nullptr ) {
        return head;
    }
    return _recursive_reverse_list(nullptr, head);
}

Node* _recursive_reverse_list(Node* prev, Node *curr)
{
    if ( curr->next == nullptr ) {
        return curr;
    }
    Node *last = recursive_reverse_list(curr, curr->next);
    if ( prev != nullptr ) {
        prev->next = curr->next;
    }
    curr->next = nullptr;
    last->next = curr;
    return curr;
}
