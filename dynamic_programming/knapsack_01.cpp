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
Given weights and values of n items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack.
In other words, given two integer arrays val[0..n-1] and wt[0..n-1] which represent values and weights associated with n items respectively.
Also given an integer W which represents knapsack capacity, find out the maximum value subset of val[] such that sum of the weights of this subset is smaller than or equal to W.
You cannot break an item, either pick the complete item or don’t pick it (0-1 property).
*/

int solve(const vector<int>& weights, const vector<int>& prices, int W) {
  int n = weights.size();

  vector<vector<int>> dp(n + 1, vector<int>(W + 1));

  // Max profit with no items picked is 0
  for (int i = 0; i <= W; i++) {
    dp[0][i] = 0;
  }

  // Max profit with knapsack capacity is 0
  for (int i = 0; i <= n; i++) {
    dp[i][0] = 0;
  }

  // Max profit at item i = dp[i - 1][W - weight[i]] if weight[i] > W
  //                        max(dp[i - 1][W - weight[i]] + prices[i], dp[i - 1][W]
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= W; j++) {
      if (weights[i - 1] > j) {
        // cout << "Cant pick item of weight " << weights[i - 1] << " as capacity is " << j << endl;
        dp[i][j] = dp[i - 1][j];
      } else {
        dp[i][j] = max(dp[i - 1][j - weights[i - 1]] + prices[i - 1], dp[i - 1][j]);
      }
    }
  }

  return dp[n][W];
}

int main(void) {

  auto prices = {60, 100, 120};
  auto weights = {10, 20, 30};
  int W = 50;

  cout << solve(weights, prices, W);

  return 0;
}