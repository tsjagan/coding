#include <iostream>
#include <functional>
#include "complex.h"
#include "timer.h"

using namespace std;

int func(int a, int b) {
    for (int i = 0; i < 10000000; i++) {
        a += b;
    }
    return a;
}
int func_no_args() {
    int a = 1, b = 1;
    for (int i = 0; i < 10000000; i++) {
        a += b;
    }
    return a;
}

int main(void) {
    auto timed = time_this(func, 1, 2);
    cout << timed.first << " and took " << timed.second.count() << endl;

    timed = time_this(func_no_args);
    cout << timed.first << " and took " << timed.second.count() << endl;

    return 0;
}