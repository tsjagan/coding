#include <stdlib.h>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using IntArray = std::vector<int>;

void two_sum(IntArray& arr, int sum)
{
    sort(arr.begin(), arr.end());
    int start = 0, end = arr.size() - 1;
    while ( start < end ) { 
        int csum = arr[start] + arr[end];
        if ( csum == sum ) {
            cout << "Found " << arr[start] << " and " << arr[end] << endl;
            return;
        } else if ( csum < sum ) {
            start++;
        } else {
            end--;
        }
    }
    cout << "No sum matches found " << endl;
    return;
}

int main(void)
{
    int n = 0;
    cout << "Enter number of values : ";
    cin >> n;

    IntArray numbers;
    for ( int i = 0; i < n; i++ ) {
        int k = 0;
        cout << "Enter number : ";
        cin >> k;
        numbers.push_back(k);
    }

    int sum = 0;
    cout << "Enter sum to look for : ";
    cin >> sum;

    two_sum(numbers, sum);
    return 0;
}