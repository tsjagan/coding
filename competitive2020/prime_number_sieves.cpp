#include <iostream>
#include <vector>
#include <list>
#include <math.h>
#include "utils.h"

using namespace std;

/*
- Find all prime numbers till a given number N
*/

vector<int> findPrimes(int n) {
    vector<int> res;
    for (int i = 1; i <= n; i++) {
        res.push_back(i);
    }

    // 1 2 3 4 5
    int limit = sqrt(n);
    for (int i = 2; i <= limit; i++) {
        int curr = i;
        if (res[i - 1] < 0) {
            continue;
        }
        while (curr+i <= n) {
            curr = curr + i;
            res[curr - 1] = -curr;
        }
    }

    vector<int> primes;
    for (auto r : res) {
        if (r > 0) {
            primes.push_back(r);
        }
    }

    return primes;
}

int main(void) {
    int n = 1;
    cout << "Enter the number :";
    cin >> n;

    auto res = findPrimes(n);
    print(res);
    return 0;
}