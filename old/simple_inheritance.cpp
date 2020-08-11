#include <iostream>

using namespace std;

class Base {
    public:
        virtual void foo() {
        }
    private:
        int c;
};



class Base1 : public Base {
    public:
        virtual void bar() {
        }
    private:
        int c;
};

class Base2: public virtual Base {
    public:
        virtual void bax() {
        }
    private:
        int b;
};

// class Derived : private Base {
class Derived : public Base1, public Base2 {
    public:
        void print() {
            std::cout << "In derived2 print " << std::endl;
        }
        void foo() {
            cout << "In derived2 foo" << endl;
        }
    private:
        int d;
};

int main(void)
{
    Derived *d = new Derived();
    Base1 *b1 = d;

    Base2 *b2 = d;

    return 0;
}
