#include <iostream>
#include "range.h"

using namespace std;

int main(void)
{
    Range<int> r1(0, 5);
    Range<int> r2(3, 8);

    r1 += r2;
    cout << r1.to_string() ;

    Range<int> r3(2, 12);
    r1 += r3;
    cout << r1.to_string() ;

    return 0;
}