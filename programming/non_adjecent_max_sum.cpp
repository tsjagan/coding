#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
using IntArray = vector<int>;

int max_nonadjacent(IntArray& arr)
{
    int kmax = (1 << 31);
    for ( int i = 0; i < arr.size(); i++ ) {
        for ( int j = i+2; j < arr.size(); j++ ) {
            int sum = arr[i] + arr[j];
            if ( sum > kmax ) {
                kmax = sum;
            }
        }
    }
    return kmax;
}

int main(void)
{
    IntArray arr;
    int n = 0;
    cout << "Enter size : ";
    cin >> n;

    for ( int i = 0; i < n; i++ ) {
        int k = 0;
        cout << "Enter number :";
        cin >> k;
        arr.push_back(k);
    }

    cout << "Max non adjacent sum is : " << max_nonadjacent(arr) << endl;
    return 0;
}
