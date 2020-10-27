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

int median(vector<vector<int>>& arrs) {
  int res = -1;
  if (arrs.empty()) {
    return res;
  }

  int k = arrs.size();
  int n = arrs[0].size();
  
  using IT = vector<int>::iterator;
  auto cmp = [](auto&& one, auto&& two) {
    return *(one.first) > *(two.first);
  };
  priority_queue<pair<IT, IT>, vector<pair<IT, IT>>, decltype(cmp)> pq(cmp);
  for (int i = 0; i < k; i++) {
    pq.push(make_pair(arrs[i].begin(), arrs[i].end()));
  }


  int median = (n * k) / 2;
  int curr = 0;
  while (curr < median) {
    auto currth = pq.top();
    cout << curr << ":" << *currth.first << " " << endl;
    pq.pop();
    curr++;
    if (currth.first == currth.second) {
      continue;
    }
    pq.push(make_pair(++currth.first, currth.second));
  }

  if (median % 2 != 0) {
    return *(pq.top().first);
  }

  int top = *(pq.top().first);
  return (top + *(pq.top().first)) / 2;
}

int main(void) {
  vector<vector<int>> arrs = {
    {5, 9, 15, 24, 111},
    {15, 21, 52, 88, 110},
    {1, 9, 11, 22, 31}
  };
     
  // 1 5 9 9 11 15 15 21 22 24 31 52 88 110 111
  cout << median(arrs) << endl;

  return 0;
}