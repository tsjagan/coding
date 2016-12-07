#include <stdlib.h>
#include <iostream>
#include <vector>
#include <map>

using namespace std;
using Arrays = vector<vector<int>>;

void quick_select()
{

}

int median_arrays(Arrays& arrays)
{
    // Naive 1:
    // sort all individual arrays
    // merge into a new large array
    // return middle of the large array

    // Naive 2:
    // Put all in new large array unsorted
    // return quick_select(large)
    // Complexity: O(2N) = O(N)


    // smart 1: more space not needed
    // sort individual arrays
    // find median of each
    // from smallest median, remove all smaller elements
    // from largest median, remove all larger elements

    for ( auto& arr: arrays ) {
        std::sort(arr.begin(), arr.end());
    }
    return 0;
}

int main(void)
{
    Arrays arr = {
        --> -2 1 2 3 3 4 5 6 7 9 10 11 12 14 18 19 22 --> 7
        // finding 9th
        // removed 5 smallest, 5 largest
        // finding 4th
        // removed 3 smallest
        // smallest median = 4th = overall median
        vector<int>{5, 2, 1, 3, 10, 14, 18},  --> 10
        vector<int>{19, -2, 11, 3, 12},       --> 11 
        vector<int>{9, 22, 4, 6, 7}       --> 7 9
    };

    return 0;
}
