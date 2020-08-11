#include <iostream>

using namespace std;
class Base {
    public:
        Base() { }
        Base(int i): x(i) { }
        void print() {
            std::cout << "In base print " << std::endl;
        }
        virtual void foo() {
            cout << "In base foo" << endl;
        }
    private:
        int x;
};

// class Derived : private Base {
class Derived1 : public Base {
    public:
        Derived1(int j, int i): Base(i), d(j) { }
        void print() {
            std::cout << "In derived1 print " << std::endl;
        }
        void foo() {
            cout << "In derived1 foo" << endl;
        }
    private:
        int d;
};

// class Derived : private Base {
class Derived2 : public virtual Base {
    public:
        Derived2(int j, int i): Base(i), d(j) { }
        void print() {
            std::cout << "In derived2 print " << std::endl;
        }
        void foo() {
            cout << "In derived2 foo" << endl;
        }
    private:
        int d;
};

class MI : public Derived1, public Derived2 {
    public:
        MI(int j, int i): Derived1(i,j), Derived2(i,j) { }
        void print() {
            std::cout << "In MI print " << std::endl;
        }
        void foo() {
            cout << "In MI foo" << endl;
        }
    private:
        int d;
};

int main(void)
{
    MI *d = new MI(3,5);
    d->print();

    return 0;
}
