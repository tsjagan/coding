#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int jumpingJack(vector<int>& jumpLengths)
{
    for (auto& b : jumpLengths) {
        cout << b << " ";
    }
    cout << endl;
    int maxReach = 0, reach = 0, jumps = 0;
    for (int i = 0; i < jumpLengths.size();) {
        while (i <= reach) {
            if ((i+jumpLengths[i]) > maxReach) {
                maxReach = (i+jumpLengths[i]);
            }
            i++;
        }
        jumps++;
        if (maxReach >= jumpLengths.size()-1) {
            break;
        }
        reach = maxReach;
        cout << "MaxReach = " << maxReach << endl;
    }
    return jumps;
}

int main(void)
{
    //vector<int> jumpLengths = {5,4,3,2,1,2,3,4,5};
    // vector<int> jumpLengths = {5,2,4,1,1,2,4,3,5};
    vector<int> jumpLengths = {4,3,1,1,4};
    // vector<int> jumpLengths = {0,1,0,2,1,0,1,3,2,1,2,1};

    int res = jumpingJack(jumpLengths);
    cout << "Result = " << res << endl;
    return 0;
}
