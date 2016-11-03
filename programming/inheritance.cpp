#include <iostream>

class Base {
    public:
        Base(int i): x(i) { }
        void base_fund() {
            std::cout << "In base func" << std::endl;
        }
        void print() {
            std::cout << "In base print " << std::endl;
        }
    private:
        int x;
};

// class Derived : private Base {
class Derived : public Base {
    public:
        Derived(int j, int i): Base(i), d(j) { }
        void print() {
            std::cout << "In derived print " << std::endl;
            Base::print();
            Base::base_fund();
        }
    private:
        int d;
};

int main(void)
{
    Derived d(3,5);
    d.print();
    d.base_fund(); // error is private inheritance
    Derived d2(4,5);
    d2 = d;

    Base b(5);
    Base b2(b);

    int arr[2] = {1,2};

    std::cout << "arr - " << 1[arr] << std::endl;
    return 0;
}
