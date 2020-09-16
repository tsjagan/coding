#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include "utils.h"

using namespace std;

/*
Given an array A of integers, find the index of values that satisfy A + B = C + D, where A,B,C & D are integers values in the array
*/

vector<int> four_sum(vector<int>& nums) {
// for each a and b -> find c,d such that c + d = a + b
// o(n*2)
//  a + b = c + d
//  a = c + d - b
  print(nums);
  unordered_map<int, pair<int,int>> ht;

  for (int i = 0; i < nums.size() - 3; i++) {
    for (int j = i + 1; j < nums.size() - 2; j++) {
     int sum = nums[i] + nums[j];
     if (ht.count(sum) == 0) {
       ht[sum] = {nums[i], nums[j]};
     } else {
        return {nums[i], nums[j], ht[sum].first, ht[sum].second};
      }
    }
  }

  return {};
}

int main(void) {
  vector<int> nums = {6, 8, 1, -3, 0, 5, 4, 17, 8, 11};
  // 0 1 5 6 
  vector<int> res = four_sum(nums);

  print(res);

  return 0;
}