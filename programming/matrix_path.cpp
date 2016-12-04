#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <typename T>
using Row = std::vector<T>;
template <typename T>
using Matrix = std::vector<Row<T>>;
double max_sum = 0.0;

// Find a path from top to bottom of a matrix of floats that has the largest sum. Print the sum and the path. 
template<typename T>
void _FindPath(Matrix<T>& matrix, int startm, int startn, Matrix<bool> visited, double curr_sum)
{
    if ( startm >= matrix.size() or startn >= matrix[0].size() ) {
        return;
    }
    if ( visited[startm][startn] == true ) {
        return;
    }
    visited[startm][startn] = true;

    if ( (startm == matrix.size()-1) and (startn == matrix[0].size()-1) ) {
        if ( curr_sum > max_sum ) {
            max_sum = curr_sum;
        }
        return;
    }

    // recurse for each adjacent cell that is not visited
    _FindPath(matrix, startm-1, startn, visited, curr_sum + matrix[startm][startn]);
    _FindPath(matrix, startm, startn-1, visited, curr_sum + matrix[startm][startn]);
    _FindPath(matrix, startm-1, startn-1, visited, curr_sum + matrix[startm][startn]);
    _FindPath(matrix, startm+1, startn, visited, curr_sum + matrix[startm][startn]);
    _FindPath(matrix, startm, startn+1, visited, curr_sum + matrix[startm][startn]);
    _FindPath(matrix, startm+1, startn+1, visited, curr_sum + matrix[startm][startn]);
    _FindPath(matrix, startm+1, startn-1, visited, curr_sum + matrix[startm][startn]);
    _FindPath(matrix, startm-1, startn+1, visited, curr_sum + matrix[startm][startn]);
}

template <typename T>
void FindPath(Matrix<T>& matrix)
{
    Row<bool> row(matrix[0].size(), false);
    Matrix<bool> visited(matrix.size(), row);
    return _FindPath(matrix, 0, 0, visited, 0);
}

int main(void)
{
    Matrix<float> matrix1 = {
        {1.0, 2.0, 3.0, 4.0, 2.5},
        {4.1, 5.7, 7.8, 2.9, 0.1},
        {6.3, 2.9, 0.0, 0.5, 2.5},
        {1.6, 1.2, 3.0, 4.0, 8.8}
    };

    Matrix<float> matrix = {
        {1.0, 2.0, 3.0, 0.0, 1.0},
        {4.1, 5.7, 7.8, 0.1, 2.0},
        {4.1, 5.7, 7.8, 0.1, 2.0},
        {1.6, 1.2, 3.0, 1.2, 3.0}
    };
  
    FindPath<float>(matrix);
    cout << "Max is : " << max_sum << endl;
    return 0;
}