#include <stdlib.h>
#include <string>
#include <iostream>
#include <vector>

using namespace std;
using IntArray = vector<int>;

int binary_search(IntArray& a, int start, int end, int look)
{
    int res = 0;
    int last = end;
    int first = start;
    while ( start <= end ) {
        int mid = (start + end) / 2;
        //cout << "Mid = " << a[mid] << ", look = " << look << endl;
        if ( a[mid] == look ) {
            int tmp = mid - 1;
            while ( a[mid] == look && mid <= last ) {
                res++;
                mid++;
            }
            while ( a[tmp] == look && tmp > first ) {
                res++;
                tmp--;
            }
            return res;
        } else if ( a[mid] < look ) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return res;
}

void swap(IntArray& arr, int a, int b)
{
    int tmp = arr[a];
    arr[a] = arr[b];
    arr[b] = tmp;
}

int main(void)
{
    IntArray a;
    int n = 0;
    cout << "Enter size : ";
    cin >> n;
    for ( int i = 0; i < n; i++ ) {
        int k = 0;
        cout << "Enter number : ";
        cin >> k;
        a.push_back(k);
    }
    int diff = 0;
    cout << "Enter diff : ";
    cin >> diff;

    int pairs = 0;
    for ( int i = 0; i < n; i++ ) {
        int look = a[i] - diff;
        if ( look < a[i] ) {
            int ret = binary_search(a, 0, i-1, look);
            if ( ret > 0 ) {
                pairs += ret;
            }
        } else if ( look > a[i] ) {
            int ret = binary_search(a, i+1, a.size()-1, look);
            if ( ret > 0 ) {
                pairs += ret;
            }
        }
    }
    cout << "pairs = " << pairs << endl;
    return 0;
}
