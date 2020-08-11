
#ifndef __COMPLEX_H__
#define __COMPLEX_H__

#include <iostream>

class Complex {
    private:
        int *arr_;
        int size_;

    public:
        Complex() {
            this->size_ = 0;
        }

        Complex(int size) {
            arr_ = new int[size];
            size_ = size;
            std::cout << "Constructed" << std::endl;
        }

        Complex(const Complex &other)
        {
            this->size_ = other.size_;
            this->arr_ = new int[this->size_];
            memcpy(this->arr_, other.arr_, this->size_);
            std::cout << "Copy constructed" << std::endl;
        }

        Complex(Complex &&other)
        {
            this->size_ = other.size_;
            this->arr_ = other.arr_;
            other.size_ = -1;
            other.arr_ = nullptr;
            std::cout << "Move constructed" << std::endl;
        }

        void print() {
            std::cout << "Printing " << size_ << std::endl;
        }
};
#endif