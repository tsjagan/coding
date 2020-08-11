#include <iostream>
#include <vector>
#include <list>
#include <math.h>
#include <limits.h>
#include "utils.h"

using namespace std;

/*
* GCD cof 2 numbers x and y is the largest number that divides both x and y.
* 
* if x == y, then GCD(x, y) = x
* If a number divides both x and y then it would also divide x - y (assuming x > y)
* this is because if K divides x and y, then (x - y) has to be a multiple of k
 */
int gcd(int x, int y) {
    if (x == y) {
        return x;
    }
    if (x > y) {
        return gcd(x-y, y);
    }
    return gcd(x, y-x);
}

int main(void) {
    int x;
    int y;
    cout << "Enter the number X : ";
    cin >> x;

    cout << "Enter the number Y : ";
    cin >> y;

    cout << gcd(x, y);

    return 0;
} 