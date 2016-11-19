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

/* we have n numbers added one at a time.
 * There is a sliding window of size K (K < N).
 * Window initally has first K elements from n.
 * Window moves to left by 1 position in each iteration.
 * Should be able to return the max from current windows.
 */

// Example:
// 4 3 2 1 8 5 9 10 0 21
// Window size = 3
// - [4 3 2] When 2 comes, 4 and 3 are essentially pointless
//   If incoming is less than ith element in mind,
//   then remove k - i
//   mind - [2], win - [4 3 2]
// - mind - [1], win - [3 2 1]
// - mind - [1 8], win - [2 1 8]
// - mind - [1 5 8], win - [1 8 5]
class Window {
    public:
        Window(IntArray& a, int size) : arr(a), k(size) {
            start = 0;
            end = k-1;
        }
        int slide_right() {
            if ( end + 1 >= arr.size() ) {
                return -1;
            }
            start++;
            end++;
            return end;
        }

        int slide_left() {
            if ( (start - 1) < 0 ) {
                return -1;
            }
            start--;
            end--;
            return end;
        }

        int maximum() {
            // keep a sorted list
            // Whenever you insert an element at position i,
            // remove all elemnts after i
            // Insert is O(log k)
            return 0;
        }

        int minimum() {
            return 0;
        }

    private:
        IntArray& arr;
        int k;

        int start;
        int end;
};

void running_maximum(IntArray& a, int k)
{
    Window window(a, k);
    while ( window.slide_right() != -1 ) {
        int m = window.maximum();
        cout << "Current maximum is : " << m << endl;
    }
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

    int k = 0;
    cout << "Enter K : ";
    cin >> k;

    running_maximum(arr, k);
    return 0;
}
