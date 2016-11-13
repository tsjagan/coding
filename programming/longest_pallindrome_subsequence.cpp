#include <iostream>
#include <memory>
#include <string>
#include <sstream>
#include <vector>
#include <map>

using namespace std;


/*
 * Test cases:
* pdccdakblqcncpbaakak

 * 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19
 * p d c c d a k b l q c  n  c  p  b  a  a  k  a  k  -> (dccd) (abccba)
 * ending at 0 = {[0,0]}
 * ending at 1 = {[1,1]}
 * ending at 2 = {[2,2]}
 * ending at 3 = {[3,3], [2,3]}
 * ending at 4 = {[4,4], [1,4]} 1 + longest(start=(>1), end=(<4))
 * ending at 5 = {[5,5]}
 * ending at 6 = {[6,6]}
 * ending at 7 = {[7,7]}
 * ending at 8 = {[8,8]}
 * ending at 9  = {[9,9]}
 * ending at 10 = {[10,10], or 1 + max(longest(start=(>2), end=(<10))),
                                   longest(start=(>3), end=(<10))))
 * ending at 11 = {[11, 11]}
      ...
      ...
 * ending at 14 = {[14, 14], longest(start=(>7), end=(<14))
 * ending at 15 = {[15, 15] or 1 + longest(start=(>5), end=(<15))
 * ending at 16 = {[0,0]}
 * ending at 17 = {[0,0]}
 * ending at 18 = {[0,0]}
 * ending at 19 = {[0,0]}
 */

// Need to lookup by start, end and letter

using Range = std::pair<uint64_t, uint64_t>;
using Results = std::map<Range, uint64_t>;
using Positions = std::vector<uint64_t>;
using LetterPositions = std::map<char, Positions>;

uint64_t longest_in_range(string& str, Results& results,
                          uint64_t start, uint64_t end)
{
  if ( start > end ) {
    return 0;
  }
  uint64_t max = 1;
  for ( auto& result : results ) {
      Range r = result.first;
      if ( r.first >= start and r.second <= end ) {
        uint64_t res = result.second;
        if ( res > max ) {
          max = res;
        }
    }
  }
  return max;
}

uint64_t longest_pallindrome_subsequence(string& str)
{
    uint64_t max = 0;
    Results results;
    uint64_t n = str.size();
    LetterPositions letters;

    for ( int i = 0; i < n; i++ ) {
      letters[i] = Positions();
    }

    for ( int i = 0; i < n; i++ ) {
      results[std::make_pair(i,i)] = 1;
      for ( auto& p : letters[str[i]] ) {
        // we find all occurenves of str[i] before i
        // then longest at i, 1 + longest(start=(>p), end=(<i))
        int start = p+1;
        int end = i-1;
        uint64_t res = 2 + longest_in_range(str, results, start, end);
        if ( res > max ) {
          max = res;
        }
        //cout << "Longest at " << p << "," << i << " = " << res << endl;
        results[std::make_pair(p,i)] = res;
      }
      letters[str[i]].push_back(i);
    }
    return max;
}

int main(void)
{
  string str;
  cin >> str;

  cout << longest_pallindrome_subsequence(str) << endl;
  return 0;
}
