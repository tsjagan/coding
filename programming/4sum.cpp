#include <stdlib.h>
#include <iostream>
#include <vector>
#include <map>

using IntArray = std::vector<int>;
using namespace std;
using Hash = std::map<int, std::pair<int, int>>;

 bool match_exists(Hash& h, IntArray& numbers, int i, int j)
{
  int ab = numbers[i] + numbers[j];
  int cd = (ab != 0) ? -(ab) : 0;
  if ( h.find(cd) != h.end() ) {
      auto v = h[cd];
      if ( i != v.first and j != v.second and
           i != v.second and j != v.first ) {
        cout << "Match - " << numbers[i] << "," << numbers[j] << " and "
             << numbers[v.first] << "," << numbers[v.second] << endl;
        return true;
      }
  }
  return false;
}

/*
 * Four numbers such that (a + b) = -(c + d)
 * 1 8 2 10 21 -11 0 13
 */
void four_sum(IntArray& numbers)
{
  Hash h;
  for ( int i = 0; i < numbers.size(); i++ ) {
    for ( int j = i+1; j < numbers.size(); j++ ) {
      match_exists(h, numbers, i, j);
      h[numbers[i] + numbers[j]] = std::make_pair(i, j);
    }
  }
  return;
}

int main(void)
{
  int n = 0;
  cout << "Enter number of values : ";
  cin >> n;

  IntArray numbers;
  for ( int i = 0; i < n; i++ ) {
    int k = 0;
    cout << "Enter number : ";
    cin >> k;
    numbers.push_back(k);
  }
  four_sum(numbers);
  return 0;
}
