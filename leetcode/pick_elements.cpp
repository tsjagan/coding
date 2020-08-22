/*`
https://leetcode.com/discuss/interview-question/804325/hyperverge-sde-online-test-question

Given an array of integers A of size N and an integer B.
You have to pick some elements from the array A while picking you have to follow the given conditions:
1. The first element to be picked should be A[1]
2. The last element to be picked should be A[n]
3. If you pick some element A[j] after A[i], then it should follow the constraints j-i >= B, j-i <= 2*B

Return the maximum sum of all picked elements.
Note: Array A has 1-based indexing.

Constraints:
1 ≤ N ≤ 10^5
1 ≤ A[I] ≤ 10^5
1 ≤  B ≤ N

Example:
A = [7, 9, 3, 8, 11, 10] , B = 2
Output: 25
Explanation: You pick {7, 8, 10}

DP logic:
If picking num at index i,
then dp[i] = A[i] + max(dp[j] for all j from <i - B> to <i - 2B>);

*/

#include <iostream>
#include <algorithm>
#include <vector>
#include "utils.h"
#include "timer.h"
#include "utils.h"

using namespace std;



int pick_elements(const vector<int>& A, int B) {
  int n = A.size();
  vector<int> dp(n, A[0]);

  for (int i = 1; i < n; i++) {
    for (int j = (i - B); j >= 0 and j >= (i - 2*B); j--) {
      dp[i] = max(dp[i], A[i] + dp[j]);
    }
  }

  return dp[n-1];
}
int main(void) {
  cout << pick_elements({7, 9, 3, 8, 11, 10}, 2) << endl;
  
  cout << pick_elements({5, 4, 3, 2, 1}, 1) << endl;

  return 0;
}