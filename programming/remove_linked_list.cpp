
// remove item from singly lined list
int remove_item(Node **head, int item)
{
    // remove_item(&head, 1)
    // remove_item(&head, 2)
    // remove_item(&head, 6)
    if ( head == nullptr || *head == nullptr ) {
        return -1;
    }
    Node *curr = *head;
    Node *prev = nullptr;
    while ( curr != nullptr ) {
        if ( curr->value == item ) {
            if ( prev != nullptr ) {
                prev->next = curr->next;
                delete curr;
            } else {
                *head = curr->next;
            }
            break;
        }
        prev = curr;
        curr = curr->next;
    }
    return 0;
}
