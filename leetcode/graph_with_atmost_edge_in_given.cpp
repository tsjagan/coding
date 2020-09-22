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
Given a graph of A nodes. Also given the weighted edges in the form of array B.

You are also given starting point C and destination point D.

Also given are some extra edges in the form of vector E.

You need to find the length of the shortest path from C to D if you can use maximum one road from the given roads in E.

All roads are one way ie they go from B[i][0] to B[i][1].
*/

void dfs(unordered_map<int, vector<vector<int>>>& graph,
         unordered_set<int>& visited,
         int curr,
         int end,
         int cost,
         int& minCost) { 
  if (visited.count(curr) > 0) {
    return;
  }
  if (curr == end) {
    minCost = min(abs(cost), minCost);
    return;
  }
  visited.insert(curr);

  if (graph.count(curr) == 0) {
    return;
  }

  for (auto& e : graph[curr]) {
    if (e[1] < 0 and cost < 0) {
      continue;
    }
    int t = cost + abs(e[1]);
    if (e[1] < 0) {
      t = -t;
    }
    dfs(graph, visited, e[0], end, t, minCost);
  }
}

int main(void) {
  int n = 4;
  vector<vector<int>> edges{{1,2,3}, {2,3,2}};
  vector<vector<int>> extra{{1,3,2}};
  int st = 1;
  int end = 4;


  for (auto& e : extra) {
    e[2] = -e[2];
    edges.push_back(move(e));
  }

cout << "Num edges = " << edges.size() << endl;
  unordered_map<int, vector<vector<int>>> graph;
  for (auto& e : edges) {
    graph[e[0]].push_back({e[1], e[2]});
  }

  // 1 -> (2, 1), (3, -2)
  // 2 -> (3, 2)
  // 3 -> (4, -2)
  int minCost = INT_MAX;
  unordered_set<int> visited;

  dfs(graph, visited, st, end, 0, minCost);

  cout << "Cost = " << (minCost == INT_MAX ? -1 : minCost) << endl;
  return 0;
}