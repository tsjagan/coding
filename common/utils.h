#ifndef __UTILS_H_
#define __UTILS_H_

#include <iostream>
#include <vector>

template <typename T>
void print(const std::vector<T>& arr) {
    for (auto& a : arr) {
        std::cout << a << " ";
    }
    std::cout << std::endl;
}

#endif