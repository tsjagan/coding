#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void Swap(vector<int>& nums, int i, int j)
{
    int t = nums[i];
    nums[i] = nums[j];
    nums[j] = t;
}

int MissingNumber(vector<int>& nums)
{
    for (int i = 0; i < nums.size(); i++) {
        while (nums[i] > 0 and i+1 != nums[i] and nums[i] <= (nums.size())) {
            for (auto& i : nums) {
                cout << i << " ";
            }
            cout << endl;
            if (nums[i] == nums[nums[i]-1]) {
                break;
            }
            cout << "Swapping " << i << " and " << nums[i]-1 << endl;
            Swap(nums, i, nums[i]-1);
        }
    }

    for (auto& i : nums) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}

int main(void)
{
    //-1,1,2,3,5,5,7,8,9
    // missing 4 and 6
    // First missing = 4
    vector<int> nums = {3,-2,5,2,5,8,7,-1,4,9,-3,0,1};
    // nums = {9,3,5,2,5,8,7,1,-1,-2,0,-3};

    int res = MissingNumber(nums);
    cout << "Result = " << res << endl;
    return 0;
}
