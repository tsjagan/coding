#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include "timer.h"
#include "utils.h"

using namespace std;

/*
 Given an array of elements, return the length of the longest subarray where all its elements are distinct.

 For example, given the array [5, 1, 3, 5, 2, 3, 4, 1], return 5 as the longest subarray of distinct elements is [5, 2, 3, 4, 1].
*/

int longest_subarray(const vector<int>& arr) {
  int res = 0;
  int curr = 0;
  int idx = 0;
  int end = arr.size() - 1;

  unordered_set<int> seen;

  while (idx <= end) {
    if (seen.count(arr[idx]) == 0) {
      curr++;
    }
    else {
      seen.clear();
      curr = 1;
    }
    seen.insert(arr[idx]);
    res = max(res, curr);
    idx++;
  }

  return res;
}

int main(void) {
  auto arr = {5, 2, 5, 4, 1};

  cout << longest_subarray(arr) << endl;
  return 0;
}