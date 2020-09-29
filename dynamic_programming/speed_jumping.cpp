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
https://www.freecodecamp.org/news/follow-these-steps-to-solve-any-dynamic-programming-interview-problem-cc98e508cd0e/

In this problem, we’re on a crazy jumping ball, trying to stop, while avoiding spikes along the way.

Here are the rules:
1) You’re given a flat runway with a bunch of spikes in it. The runway is represented by a boolean array which indicates if a particular (discrete) spot is clear of spikes. It is True for clear and False for not clear.

*/

bool solve(vector<int>& spikes, int speed)
{
  int n = spikes.size();
  vector<vector<bool>> dp(n, vector<bool>(n, false));

  for (int i = 0; i < n; i++) {
    dp[i][0] = (spikes[i] == 0 ? false : true);
  }

  // dp[i][s] = dp[i - s][s] or dp[i - s][s - 1] or dp[i - s][s + 1]
  for (int i = 1; i < n; i++) {
    for (int s = 1; s < n; s++) {
      if (i - s < 0 or spikes[i - s] == 0) {
        continue;
      }
      dp[i][s] = dp[i - s][s] || dp[i - s][s - 1] || dp[i - s][s + 1];
    }
  }

  return dp[0][speed];
}

int main(void) {
  // 0 = spike, 1 is clear
  vector<int> spikes = {1, 0, 1, 1, 1, 0, 1, 1, 0, 1, 1};
  int speed = 3;

  cout << solve(spikes, speed) << endl;
  return 0;
}