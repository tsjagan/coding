#include <iostream>
#include <memory>
#include <string>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

/*
 * Test cases:
 * avadakadavrakl
 * Ending at 0 : (0,0)
 * Ending at 1 : (1,1)
 * Ending at 2 : (0,2)
 * Ending at 3 : (0,0)
 * Ending at 4 : (0,0)
 * Ending at 5 : (0,0)
 * Ending at 6 : (0,0)
 * Ending at 7 : (0,0)
 * Ending at 8 : (0,0)
 * Ending at 9 : (0,0)
 * Ending at 10: (0,0)
 */

uint64_t longest_pallindrome_substring(string& str)
{
  int dp[str.size()][str.size()];
  int max = 0;

  for ( int i = 0; i < str.size(); i++ ) {
    for ( int j = 0; j < str.size(); j++ ) {
      dp[i][j] = ( i == j ) ? 1 : 0;
    }
  }

  // avadakadavrakl
  for ( int i = 0; i < str.size(); i++ ) {
    for ( int j = 0; j < i; j++ ) {
      if (  str[j] != str[i] ) {
        continue;
      }
      if ( (j+1) > (i-1) ) {
        continue;
      }
      int len = (i-1) - (j+1) + 1;
      if ( dp[j+1][i-1] == len ) {
        dp[j][i] = 2 + dp[j+1][i-1];
        if ( dp[j][i] > max ) {
          max = dp[j][i];
          cout << "New max from " << j << " to " << i << endl;
        }
      }
    }
  }
  return max;
}

int main(void)
{
  string str;
  cin >> str;

  cout << longest_pallindrome_substring(str) << endl;
  return 0;
}
