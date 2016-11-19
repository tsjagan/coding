#include <iostream>
#include "heap.h"

using namespace std;

int main(void)
{
    heap::ArrayHeap h(10);
    h.insert(2);
    cout << "Min is = " << h.min() << endl;
    h.insert(3);
    cout << "Min is = " << h.min() << endl;
    h.insert(4);
    cout << "Min is = " << h.min() << endl;
    h.insert(1);
    cout << "Min is = " << h.min() << endl;
    h.insert(0);
    cout << "Min is = " << h.min() << endl;
    h.insert(8);
    cout << "Min is = " << h.min() << endl;
    h.insert(9);
    cout << "Min is = " << h.min() << endl;
    h.insert(5);
    cout << "Min is = " << h.min() << endl;
    h.insert(-1);
    cout << "Min is = " << h.min() << endl;

    return 0;
}