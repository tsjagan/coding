#include <stdlib.h>
#include <iostream>

#include "linked_list.h"

ll::SinglyLinkedList::Ptr
merge_ll(ll::SinglyLinkedList::Ptr l1, ll::SinglyLinkedList::Ptr l2)
{
    auto l = std::make_shared<ll::SinglyLinkedList>();
    auto n1 = l1->head();
    auto n2 = l2->head();
    while ( n1 != nullptr and n2 != nullptr ) {
        if ( n1->value_ < n2->value_ ) {
            l->add(n1);
            n1 = n1->next_;
        } else if ( n1->value_ > n2->value_ ) {
            l->add(n2);
            n2 = n2->next_;
        } else {
            l->add(n2);
            n1 = n1->next_;
            n2 = n2->next_;
        }
    }
    auto n = (n1 == nullptr ) ? n2 : n1;
    while ( n != nullptr ) {
        l->add(n);
        n = n->next_;
    }
    return l;
}

int main(void)
{
    ll::SinglyLinkedList::Ptr l1 = std::make_shared<ll::SinglyLinkedList>();
    l1->add(0);
    l1->add(1);
    l1->add(2);
    l1->add(3);
    l1->add(5);

    ll::SinglyLinkedList::Ptr l2 = std::make_shared<ll::SinglyLinkedList>();
    l2->add(0);
    l2->add(2);
    l2->add(4);
    l2->add(6);
    l2->add(7);

    cout << l1->print() << endl;
    cout << l2->print() << endl;

    auto merged = merge_ll(l1, l2);
    cout << merged->print() << endl;
    return 0;
}