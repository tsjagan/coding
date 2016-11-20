#include <stdlib.h>
#include <iostream>

#include "linked_list.h"

using namespace std;

int main(void)
{
    auto dll = std::make_shared<ll::DoublyLinkedList>();
    dll->add(std::make_shared<ll::Node>(1));
    dll->add(std::make_shared<ll::Node>(5));
    dll->add(std::make_shared<ll::Node>(3));
    dll->add(std::make_shared<ll::Node>(2));
    dll->add(std::make_shared<ll::Node>(4));

    cout << dll->tostring() << endl;
    return 0;
}