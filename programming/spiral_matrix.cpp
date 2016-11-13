#include <stdlib.h>
#include <string>
#include <iostream>
#include <vector>

using namespace std;
using Row = std::vector<int>;
using Matrix = std::vector<Row>;

bool move_right(Matrix& m, int& i, int& j, int limit)
{
  // cout << endl << "Moving right ";
  bool changed = false;
  while ( j < limit ) {
    cout << m[i][j] << " ";
    j++;
    changed = true;
  }
  return changed;
}

bool move_down(Matrix& m, int& i, int& j, int limit)
{
  // cout << endl << "Moving down ";
  bool changed = false;
  while ( i < limit ) {
    cout << m[i][j] << " ";
    i++;
    changed = true;
  }
  return changed;
}

bool move_left(Matrix& m, int& i, int& j, int limit)
{
  // cout << endl << "Moving left ";
  bool changed = false;
  while ( j > limit ) {
    cout << m[i][j] << " ";
    j--;
    changed = true;
  }
  return changed;
}

bool move_up(Matrix& m, int& i, int& j, int limit)
{
  bool changed = false;
  while ( i > limit ) {
      cout << m[i][j] << " ";
      i--;
      changed = true;
  }
  return changed;
}

void spiral_print(Matrix& m)
{
  bool can_move = true;
  int dlimit = m.size() - 1;
  int rlimit = 0, llimit = 0, ulimit = 1;
  if ( m.size() > 0 ) {
    rlimit = m[0].size() - 1;
  }
  int i = 0, j = 0;
  bool first = true;
  while ( can_move == true ) {
    can_move = false;
    if ( j < rlimit ) {
      can_move = move_right(m, i, j, rlimit);
    }
    if ( (first == true or can_move == true) and i < dlimit ) {
      can_move = move_down(m, i, j, dlimit);
    } else {
      can_move = false;
    }
    if ( can_move == true and j > llimit ) {
      can_move = move_left(m, i, j, llimit);
    } else {
      can_move = false;
    }
    if ( can_move == true and i > ulimit ) {
      can_move = move_up(m, i, j, ulimit);
    } else {
      can_move = false;
    }

    first = false;
    rlimit--;
    dlimit--;
    llimit++;
    ulimit++;
  }
  cout << m[i][j];
}

int main(void)
{
  {
    Matrix matrix;
    cout << "Single row, single column " << endl;
    matrix.push_back(Row({1}));
    spiral_print(matrix);
    cout << endl;
  }

  {
    Matrix matrix;
    cout << "Single row " << endl;
    matrix.push_back(Row({1, 2, 3, 4, 5}));
    spiral_print(matrix);
    cout << endl;
  }

  {
    Matrix matrix;
    cout << "Two rows " << endl;
    matrix.push_back(Row({6, 7, 8, 9, 10}));
    matrix.push_back(Row({11, 12, 13, 14, 15}));
    spiral_print(matrix);
    cout << endl;
  }

  {
    Matrix matrix;
    cout << "4*5 matrix " << endl;
    matrix.push_back(Row({1, 2, 3, 4, 5}));
    matrix.push_back(Row({6, 7, 8, 9, 10}));
    matrix.push_back(Row({11, 12, 13, 14, 15}));
    matrix.push_back(Row({16, 17, 18, 19, 20}));
    spiral_print(matrix);
    cout << endl;
  }

  {
    Matrix matrix;
    cout << "Single column : " << endl;
    matrix.push_back(Row({1}));
    matrix.push_back(Row({2}));
    matrix.push_back(Row({3}));
    spiral_print(matrix);
    cout << endl;
  }

  {
    Matrix matrix;
    cout << "Two rows, two columns : " << endl;
    matrix.push_back(Row({1, 2}));
    matrix.push_back(Row({3, 4}));
    matrix.push_back(Row({5, 6}));
    spiral_print(matrix);
    cout << endl;
  }

  return 0;
}
