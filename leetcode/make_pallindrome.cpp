/*
This problem was asked by Google.

Given a string which we can delete at most k, return whether you can make a palindrome.
For example, given 'waterrfetawx' and a k of 2, you could delete f and x to get 'waterretaw'.
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include "timer.h"

using namespace std;

bool is_palindrome(const string& str, int st, int end) {
    while (st < end and str[st] == str[end]) {
        st++;
        end--;
    }
    return (st == end);
}

// absfgsba 
bool _edits_to_palindrome(string& str, int left, int right, int k) {
    if (left >= right) {
        return true;
    }

    if (k < 0) {
        return false;
    }

    if (is_palindrome(str, left, right)) {
        return true;
    }
    if (str[left] == str[right]) {
        return _edits_to_palindrome(str, left + 1, right - 1, k) or
               _edits_to_palindrome(str, left + 1, right, k - 1) or
               _edits_to_palindrome(str, left, right - 1, k - 1);
    }

    return _edits_to_palindrome(str, left + 1, right, k - 1) or
           _edits_to_palindrome(str, left, right - 1, k - 1);
}

bool edits_to_palindrome(string& str, int k) {
    return _edits_to_palindrome(str, 0, str.size() - 1, k);
}

bool edits_to_palindrome_dp(const string& str, int k) {
    int n = str.size();
    vector<vector<int>> dp(n, vector<int>(n, k + 1));

    for (int i = n - 1; i >= 0; i--) {
        for (int j = i; j < n; j++) {
            if (i == j) {
                dp[i][j] = 0;
            } else if (i + 1 == j) {
                dp[i][j] = (str[i] == str[j] ? 0 : 1);
            } else {
                if (str[i] == str[j]) {
                    dp[i][j] = dp[i + 1][j - 1];
                } else {
                    dp[i][j] = 1 + min(dp[i][j - 1], dp[i + 1][j]);
                }
            }
        }
    }

    return (dp[0][n - 1] <= k);
}

// <str> is palindrome break and return
// all strings for length 1 is true
// otherwise:
//    - (str[i] == str[j] and dp[k][i+1][j-1] == true) or
//    - (dp[k-1][i][j-1] == true) or
//    - (dp[k-1][i+1][j] == true) or
int main(void) {
    string str;
    int k;
    cout << "Enter string : "; 
    cin >> str;

    cout << "Enter K : "; 
    cin >> k;

    auto ret = time_this(edits_to_palindrome, str, k);
    cout << ret.first << ":" << ret.second.count() << endl;

    ret = time_this(edits_to_palindrome_dp, str, k);
    cout << ret.first << ":" << ret.second.count() << endl;
    return 0;
}