#include <stdlib.h>
#include <string>
#include <vector>
#include <iostream>
#include <map>

using IntArray = std::vector<int>;
using Hash = std::map<int, int>;
using namespace std;

// numbers  : 1 8 3 2 7 -1 9
// ordering : 8 7 -1
// True

// numbers  : 1 8 3 2 7 -1 9
// ordering : 8 -1 2
// False

// naive solution: O(n * m)
// curr = 0
// for each n in ordering: O(m)
//    pos = lookup(n in numbers) O(n)
//    if ( pos < curr )
//      return False
//    curr = pos
// return True;
bool check_ordering(IntArray& numbers, IntArray& ordering)
{
  Hash h;
  for ( int i = 0; i < ordering.size(); i++ ) {
    h[ordering[i]] = i;
  }
  int curr = -1;
  for ( int i = 0; i < numbers.size(); i++ ) {
      if ( h.find(numbers[i]) != h.end() ) {
          if ( h[numbers[i]] < curr ) {
            cout << numbers[i] << " is out of order " << endl;
            return false;
          }
          curr = h[numbers[i]];
      }
  }
  return true;
}

int main(void)
{
  int n = 0, m = 0;
  cout << "Enter number of numbers : ";
  cin >> m;

  IntArray numbers, ordering;
  for ( int i = 0; i < m; i++ ) {
    int k = 0;
    cout << "Enter number : ";
    cin >> k;
    numbers.push_back(k);
  }
  cout << "Enter num ordering : ";
  cin >> n;
  for ( int i = 0; i < n; i++ ) {
    int k = 0;
    cout << "Enter number : ";
    cin >> k;
    ordering.push_back(k);
  }
  cout << check_ordering(numbers, ordering) << endl;
  return 0;
}
