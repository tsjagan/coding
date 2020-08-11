#ifndef __TIMER_H__
#define __TIMER_H__

#include <utility>
#include <chrono>

/*
 * usage:
 * time_this(f, arg1, arg2...)
 */
template <typename F, typename... Args>
decltype(auto) time_this(F func, Args&&... args) {
    auto start = std::chrono::system_clock::now();

    auto ret = func(std::forward<Args>(args)...);
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> diff = end - start;
    return std::make_pair(ret, diff);
}

#endif