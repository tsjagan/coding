#include <stdlib.h>
#include <iostream>
#include <map>
#include <algorithm>

#include "median.h"

using namespace std;
using Arrays = vector<Array>;

int median_arrays(Arrays& arrays)
{
    int total = 0;
    for ( auto& arr: arrays ) {
        total += arr.size();
    }

    int median_pos = (total/2);
    int i = 0;
    while ( true ) {
        for ( auto& arr: arrays ) {
            Select::print(arr);
        }
        cout << "Finding : " << median_pos << endl;
        std::pair <int, int> smallest = std::make_pair(-1, 0x7FFFFFFF);
        for ( auto& arr: arrays ) {
            int pos = Select::median(arr);
            cout << "Select of array = " << arr[pos] << endl;
            if ( arr[pos] < smallest.second  ) {
                smallest = std::make_pair(pos, arr[pos]);
            }
        }
        int smaller = 0;
        for ( auto& arr: arrays ) {
            auto it = std::remove_if(
                arr.begin(), arr.end(), 
                [&](int x)->bool{
                    if ( x < smallest.second ) {
                        smaller++;
                        return true;
                    }
                    return false;
                });
            arr.erase(it, arr.end());
        }
        median_pos = median_pos - smaller;
        if ( median_pos == 0 ) {
            return smallest.second;
        }
        if ( smaller == 0 ) {
            Array tmp;
            for ( auto& arr: arrays ) {
                tmp.insert(tmp.begin(), arr.begin(), arr.end());
            }
            Select::print(tmp);
            cout << "Returning " << median_pos << endl;
            return Select::select(tmp, median_pos);
        }
    }
    return 0;
}

int main(void)
{
    Arrays arr = {
        // -2, 1, 2, 3, 3, 4, 6, 9, 10, 11, 12, 14, 17, 18, 19, 22
        vector<int>{2, 1, 3, 10, 14, 18},
        vector<int>{19, -2, 11, 3, 12},
        vector<int>{9, 17, 4, 6, 22}
    };

    cout << "*************" << endl;
    cout << "Median of arrays = " << median_arrays(arr) << endl;

    cout << "*************" << endl;
    for ( auto& a: arr ) {
        Select::print(a);
        cout << "Median is = " << a[Select::median(a)] << endl;
    }

    cout << "*************" << endl;
    for ( auto& a: arr ) {
        Select::print(a);
        cout << "First is = " << a[Select::select(a, 0)] << endl;
    }

    cout << "*************" << endl;
    for ( auto& a: arr ) {
        Select::print(a);
        cout << "Second is = " << a[Select::select(a, 1)] << endl;
    }

    return 0;
}
