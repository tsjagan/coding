#include <stdlib.h>
#include <iostream>
#include <string>
#include <map>

using namespace std;
using Hash = std::map<char, int>;
/*
 * Ex: s1= abrac adabrac, s2=abc -> res = brac
 */
string max_subsequence(string& s1, string& s2)
{
  string res;
  Hash to_find, found;
  int total = s2.size();
  for ( auto& s : s1 ){
    found[s] = 0;
    to_find[s] = 0;
  }
  for ( auto& s : s2 ){
    found[s] = 0;
    to_find[s] = 0;
  }
  for ( auto& s : s2 ){
    to_find[s]++;
  }

  // window is from start to curr
  // Begin with start,curr = 0,0
  int start = 0;
  int curr = 0, found_till_now=0;
  while ( curr < s1.size() ) {
    char c = s1[curr];
    if ( to_find[c] != 0 ) {
      if ( to_find[c] > found[c] ) {
        found_till_now++;
      }
      found[c]++;
    }
    if ( found_till_now == total ) {
      cout << "Found first match at " << start << " and " << curr << endl;
      break;
    }
    curr++;
  }
  // now window is start,curr (0,first_match)
  // Try to move curr till we find next matching char
  while ( start < curr and curr < s1.size() ) {
    while ( start < curr and (to_find[s1[start]] == 0 ||
            found[s1[start]] > to_find[s1[start]]) ) {
      // move forward start as much as possible
      if ( found[s1[start]] > 0 ) {
        found[s1[start]]--;
      }
      cout << "Moved start to " << start+1 << endl;
      start++;
    }
    cout << "Match from " << start << " and " << curr << endl;
    curr++;
    while ( curr < s1.size() ) {
      if ( to_find[s1[curr]] != 0 ) {
        found[s1[curr]]++;
      }
      if ( s1[curr] == s1[start] ) {
        break;
      }
      curr++;
    }
  }
  return res;
}

int main(void)
{
  string s1, s2;
  cout << "Enter string 1 : ";
  cin >> s1;

  cout << "Enter string 2 :";
  cin >> s2;

  cout << max_subsequence(s1, s2) << endl;
  return 0;
}
