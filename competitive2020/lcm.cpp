#include <iostream>
#include <vector>
#include <list>
#include <math.h>
#include <limits.h>
#include "utils.h"

using namespace std;

/*
 * Simple solution:
 * LCM of 2 numbers x and y is the smallest number that is divisible by both x and y.
 * For eg: x = 13, y = 37 and LCM(x, y) = 481
 */
int lcm(int x, int y) {
    int larger = max(x, y);
    int smaller = min(x, y);

    int res = larger;
    while (res <= (y * x)) {
        if (res % x == 0 and res % y == 0) {
            return res;
        }
        res = res + larger;
    }

    return res;
}

// lcm(x, y) = abs(x * y) / gcd(x,y);
// see gcd.cpp for algorithm to calculate gcd
int main(void) {
    int x;
    int y;
    cout << "Enter the number X : ";
    cin >> x;

    cout << "Enter the number Y : ";
    cin >> y;

    cout << lcm(x, y);

    return 0;
} 