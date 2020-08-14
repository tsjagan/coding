// https://codeforces.com/contest/597/problem/B

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void print(vector<pair<int, int>>& orders) {
    for (auto& e : orders) {
        cout << "[" << e.first << ":" << e.second << "],";
    }
    cout << endl;
}

int solve(vector<pair<int, int>>& orders) {
    auto cmp = [](auto&& one, auto&& two) {
        if (one.second != two.second) {
            return one.second < two.second;
        }
        return one.first < two.first;
    };
    sort(orders.begin(), orders.end(), cmp);
    // entry -> num_intersections
    // [1,10], [2,3], [4,6], [7,9] -> [2,3], [4,6], [7,9], [1,10]
    // [1,3], [2,10], [4,6], [7,9] -> [1,3], [4,6], [7,9], [2,10]
    // [2,9], [1,9]                -> [1,9], [2,9]
    print(orders);
    int res = 0;
    int last = 0;
    for (int i = 0; i < orders.size(); i++) {
        if (orders[i].first > last) {
            res++;
            last = orders[i].second;
        }
    }

    return res;
}

int main(void) {
    int n = 0;
    cout << "Enter n :";
    cin >> n;

    vector<pair<int, int>> orders;
    for (int i = 0; i < n; i++) {
        int start, end;
        cout << "Enter start :" ;
        cin >> start;
        cout << "Enter end:" ;
        cin >> end;
        orders.push_back({start, end});
    }
    int maxOrders = solve(orders);
    cout << "Max orders = " << maxOrders << endl;
    return 0;
}

