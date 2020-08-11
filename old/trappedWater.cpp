#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int WaterContent(vector<int>& bricks)
{
    for (auto& b : bricks) {
        cout << b << " ";
    }
    cout << endl;
    int total = 0;
    int left = 0, right = bricks.size()-1;
    int lmax = bricks[left], rmax = bricks[right];
    while (left <= right) {
        if (bricks[left] > lmax) {
            lmax = bricks[left];
        }
        if (bricks[right] > rmax) {
            rmax = bricks[right];
        }
        if (bricks[left] < bricks[right]) {
            int fill = min(lmax, rmax) - bricks[left];
            cout << "Fill at " << left << ":" << bricks[left] << " is " << fill << endl;
            if (fill >= 0) {
                total += fill;
            }
            left++;
        } else {
            int fill = min(lmax, rmax) - bricks[right];
            cout << "Fill at " << right << ":" << bricks[right] << " is " << fill << endl;
            if (fill >= 0) {
                total += fill;
            }
            right--;
        }
    }
    return total;
}

int main(void)
{
    //vector<int> bricks = {5,4,3,2,1,2,3,4,5};
    // vector<int> bricks = {5,2,4,1,1,2,4,3,5};
    vector<int> bricks = {1,0,3,1,0,1,0,1,0,2};
    // vector<int> bricks = {0,1,0,2,1,0,1,3,2,1,2,1};

    int res = WaterContent(bricks);
    cout << "Result = " << res << endl;
    return 0;
}
