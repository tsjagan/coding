#include <iostream>
#include <memory>
#include "complex.h"

using namespace std;

template <typename T>
void func(T&& c) {
    c.print();
} 


template <typename T>
class MyUniquePtr {
    private:
        T* ptr_;
    public:
        MyUniquePtr(T* ptr) : ptr_(ptr) { }

        MyUniquePtr(MyUniquePtr&& other) {
            this->ptr_ = other.ptr_;
        }

        T* operator->() {
            return ptr_;
        }

        ~MyUniquePtr() {
            if (ptr_ != nullptr) {
                cout << "Destructing ptr";
                delete ptr_;
            }
        }
};

template<typename T, typename... Args>
MyUniquePtr<T> myMakePtr(Args&&... args) {
    return MyUniquePtr<T>(forward<Args>(args)...);
}
int main(void) {
    Complex c1(1);

    auto ptr1 = myMakePtr<Complex>(&c1);

    auto ptr2 = move(ptr1);

    ptr2->print();

    return 0;
}