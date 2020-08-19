#ifndef __UTILS_H_
#define __UTILS_H_

#include <iostream>
#include <vector>
#include <string>

template <typename T>
void print(const std::vector<T>& arr) {
    for (auto& a : arr) {
        std::cout << a << " ";
    }
    std::cout << std::endl;
}


bool is_palindrome(const std::string& str, int st, int end) {
    while (st < end && str[st] == str[end]) {
        st++;
        end--;
    }
    return (st >= end);
}

#endif