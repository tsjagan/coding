#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
using IntArray = vector<int>;

void swap(IntArray& arr, int a, int b)
{
    int tmp = arr[a];
    arr[a] = arr[b];
    arr[b] = tmp;
}

void print(IntArray& arr)
{
    for ( auto& a : arr ) {
        cout <<  a << " ";
    }
    cout << endl;
}

int quick_sort(IntArray& arr, int small, int big)
{
    if ( small >= big ) {
        return 0;
    }
    int start = small, end = big;
    int equal = small;
    int curr = small, pivot = arr[(small + big)/2];
    cout << "Pivot is " << pivot
         << ",small = " << small
         << ",big = " << big << endl;
    while ( curr <= big ) {
        if ( arr[curr] < pivot ) {
            swap(arr, curr, small);
            small++;
            equal++;
            curr++;
        } else if ( arr[curr] > pivot ) {
            swap(arr, curr, big);
            big--;
        } else {
            swap(arr, curr, equal);
            equal++;
            curr++;
        }
    }
    print(arr);
    quick_sort(arr, start, small-1);
    quick_sort(arr, equal, end);
    return 0;
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

    quick_sort(arr, 0, arr.size()-1);
    print(arr);
    return 0;
}
