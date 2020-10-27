#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include "timer.h"
#include "utils.h"

using namespace std;


/*
You are given an array of nonnegative integers.
Let's say you start at the beginning of the array and are trying to advance to the end.
You can advance at most, the number of steps that you're currently on. Determine whether you can get to the end of the array.

For example, given the array [1, 3, 1, 2, 0, 1], we can go from indices 0 -> 1 -> 3 -> 5, so return true.

Given the array [1, 2, 1, 0, 0], we can't reach the end, so return false.
*/

bool advance_to_end(vector<int>&& arr) {
  int n = arr.size();
  if (n <= 1) {
    return true;
  }

  bool ret = false;
  int reach = n - 1;

  for (int i = n - 2; i >= 0; i--) {
    if (arr[i] + i >= reach) {
      reach = i;
    }
  }

  return (reach == 0);
}

int main(void) {
  //          0  1  2  3  4  5                             
  // auto arr = {1, 3, 1, 2, 0, 1};
  auto arr = {1, 2, 1, 1, 0, 0};

  cout << advance_to_end(arr) << endl;

  
  return 0;
}