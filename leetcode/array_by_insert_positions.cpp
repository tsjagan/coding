#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include "timer.h"
#include "utils.h"

using namespace std;

/*
Given an array of elements, along with their insertion position. Find the final array.
Basically, we're supposed to shift the elements by 1 if there's an element already at that index.

Example:
arr = {1, 2, 3, 4, 5, 6, 9}
index = {0, 1, 2, 1, 2, 1, 2}

0 -> 1
1 -> 6
2 -> 9
3 -> 4, 5, 2, 3

Output = {1,6,9,4,5,2,3}

Sequence:

1 inserted at index 0 -> {1}
2 inserted at index 1 -> {1,2}
3 inserted at index 2 -> {1,2,3}
4 inserted at index 1, elements shifted -> {1,4,2,3}
5 inserted at index 2, elements shifted -> {1,4,5,2,3}
*/

vector<int> reorder(const auto& arr, const auto& indices) {
  vector<int> res;

  int n = arr.size();


  return res;
}

int main(void) {

  vector<int> arr = {1, 2, 3, 4, 5};
  vector<int> indices = {0, 1, 2, 1, 2};

  auto res = reorder(arr, indices);

  print(res);

  return 0;
}