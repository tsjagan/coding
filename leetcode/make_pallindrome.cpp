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

int main(void) {
    string str;
    int k;
    cout << "Enter string : "; 
    cin >> str;

    cout << "Enter K : "; 
    cin >> k;

    auto ret = time_this(edits_to_palindrome, str, k);
    cout << ret.first << ":" << ret.second.count() << endl;
    return 0;
}