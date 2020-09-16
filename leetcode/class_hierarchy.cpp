#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include "timer.h"
#include "utils.h"

using namespace std;

/*
Suppose you are to write an IDE plugin whose purpose is to display (print) the class hierarchy of a project.

Implement a function that prints this class hierarchy in pre-order (root, then rest). You can assume your function takes as input a List, where the Clazz type is defined as:

Clazz = { name: String, parent: Clazz }
Sample Input 1:

[{name: "B", parent=A}, {name: "C", parent=A}, {name: "X1", parent=null}, {name: "E", parent=B}, {name: "D", parent=A}, {name: "A", parent=null}, {name: "F", parent=B}];
Output: (2 valid outputs) ['A', 'B', 'E', 'F', 'C', 'D', 'X1'] OR ['X1', 'A', 'B', 'E', 'F', 'C', 'D']
*/

void dfs(unordered_map<string, vector<string>>& nodes,
         const string& curr,
         vector<string>& res) {
  if (not curr.empty()) {
    res.push_back(curr);
  }

  for (auto& c : nodes[curr]) {
    dfs(nodes, c, res);
  }
  return;
}

vector<string> traverse(vector<vector<string>>& classz) {
  vector<string> res;

  unordered_map<string, vector<string>> nodes;
  for (auto& entry : classz) {
    nodes[entry[1]].push_back(entry[0]);
  }

  dfs(nodes, "", res);

  return res;
}

int main(void) {
  vector<vector<string>> classz = {{"c", "a"}, {"x1",""}, {"e", "b"}, {"b","a"}, {"d", "a"}, {"a", ""}, {"f", "b"}};

  vector<string> res = traverse(classz);
  print(res);

  return 0;
}