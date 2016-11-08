#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;
/*
 * Example:
 * s1 = abcdef
 * s2 = bacelm
 &
 * Example:
 * s1 = ab
 * s2 = abc
 */
int edit_distance(string& s1, string& s2)
{
  // if either s1 or s2 has length 0, then edit distance
  // is length of other string.
  // if chars at a position are equal then decrement both
  // edit_distance[s1][s2] = edit_distance[]
  int d[s1.size()+1][s2.size()+1];
  for ( int i = 0; i <= s1.size(); i++ ) {
    // In each interation of the inner loop,
    // we are trying to find edit distance from s1[0...i]
    // to s2[0], s2[1]....s2[s2.size()-1]
    for ( int j = 0; j <= s2.size(); j++ ) {
      // d[i][j] stored distance from s1[0...i] to s2[0...j]
      if ( i == 0 ) { // s1 is empty
        d[i][j] = j;
      } else if ( j == 0 ) { // s2 is emoty
        d[i][j] = i;
      } else if ( s1[i-1] == s2[j-1] ) {
        // ex: s1 = abc, s2 = dec, i = 2, j = 2
        d[i][j] = d[i-1][j-1];
      } else {
        // 1. We can either remove this character -> 1 + d[i][j-1]
        // ex: s1 = akc, s2 = def, i = 2, j = 2. If we delete s1[i] from s1,
        // then we have to convert "ak" to "def" to get our result
        d[i][j] = 1 + std::min(d[i][j-1], d[i-1][j], d[i-1][j-1]);
      }
    }
  }
  return d[s1.size()][s2.size()];
}

int main(void)
{
  string s1, s2;
  cout << "Enter string 1 : ";
  cin >> s1;

  cout << "Enter string 2 :";
  cin >> s2;

  cout << edit_distance(s1, s2) << endl;
  return 0;
}
