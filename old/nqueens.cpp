#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <string>
#include <vector>

using namespace std;
using Pos = pair<int, int>;
using Row = vector<int>;
using Queens = vector<Pos>;

bool
CheckStraight(Pos& pos1, Pos& pos2)
{
    if (pos1.first == pos2.first or
        pos1.second == pos2.second) {
        return true;
    }
    return false;
}

bool
CheckDiagonal(Pos& pos1, Pos& pos2)
{
    int rd = abs(pos1.first - pos2.first);
    int cd = abs(pos1.second - pos2.second);
    if (rd == cd) {
        return true;
    }
    return false;
}

bool
Nqueens(int n, Queens& queens)
{
    if (queens.size() == n) {
        return true;
    }

    bool res = false;
    Pos last = (queens.size() > 0) ? queens.back() : make_pair(-1,0);
    for (int j = 0; j < n; j++) {
        Pos curr = make_pair(last.first+1,j);
        bool clash = false;
        for (int q = 0; q < queens.size(); q++) {
            if (CheckStraight(curr, queens[q]) or
                CheckDiagonal(curr, queens[q])) {
                clash = true;
                break;
            }
        }
        if (clash == false) {
            queens.push_back(curr);
            res = Nqueens(n, queens);
            if (res == false) {
                queens.pop_back();
            }
        }
    }
    return res;
}

int main(void)
{
    Queens q;
    Nqueens(4, q);
    vector<vector<string>> res;
    for (int i = 0; i < q.size(); i++) {
        cout << q[i].first << " " << q[i].second << endl;
    }
    return 0;
}
