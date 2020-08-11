#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

double distance(const auto& p1, const auto& p2) {
    return sqrt(pow(p2[0] - p1[0], 2) + pow(p2[1] - p1[1], 2));
}

double solve(vector<vector<int>>& studs) {
    auto cmp = [](const auto& s1, const auto& s2) {
        return distance(s1, vector<int>{0,0}) < distance(s2, vector<int>{0,0});
    };

    sort(studs.begin(), studs.end(), cmp);
    double res = 0;
    for (int i = 0; i < studs.size(); i += 2) {
        res += distance(studs[i], studs[i + 1]);
        cout << res << ", ";
    }
    return res;
}

int main(void) {
    int n = 0;
    cin >> n;

    vector<vector<int>> studs;
    for (int i = 0; i < 2*n; i++) {
        int x, y;
        cin >> x;
        cin >> y;
        studs.push_back({x,y});
    }

    cout << solve(studs) << endl;
    return 0;
}