// https://leetcode.com/problems/valid-palindrome-ii/


#include <iostream>
#include <algorithm>
#include <vector>
#include "utils.h"
#include "timer.h"

using namespace std;

bool _valid_palindrome(const string& str, int left, int right, int k) {
    if (left >= right) {
        return true;
    }

    while (left < right and str[left] == str[right]) {
        left++;
        right--;
    }

    if (left < right) {
        cout << "Mismatch at " << str[left] << " and " << str[right] << endl;
        return is_palindrome(str, left + 1, right) || is_palindrome(str, left, right - 1);
         
    }
    return true;
}

bool valid_palindrome(const string& str) {
    // recursive is easy.
    // for each character, check if removing it makes it a palindrome.
    // asgddsa
    // asfasadsa
    int st = 0;
    int end = str.size() - 1;
    return _valid_palindrome(str, st, end, 1);
}

int main(void) {
    string str;
    int k;
    cout << "Enter string : "; 
    cin >> str;

    auto ret = valid_palindrome(str);
    cout << "ret : " << ret << endl;
    return 0;
}