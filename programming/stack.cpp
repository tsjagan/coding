#include <stdlib.h>
#include <iostream>

using namespace std;

class Stack {
    public:
        Stack(int size) : top_(-1), size_(size) {
            this->stack_ = new int[size];
        }
        ~Stack() {
            if ( this->stack_ != nullptr ) {
                delete this->stack_;
            }
        }
        int push(int item) {
            if ( this->top_ == this->size_ ) {
                return -1;
            }
            this->stack_[++this->top_] = item;
        }
        void pop() {
            if ( this->top_ == -1 ) {
                cout << "Stack is empty" << endl;
                return;
            }
            this->top_--;
        }
        int peek(int& item) {
            if ( this->top_ == -1 ) {
                cout << "Stack is empty" << endl;
                return -1;
            }
            item = this->stack_[this->top_];
            return 0;
        }
    private:
        int *stack_;
        uint32_t top_;
        uint32_t size_;
};


int main(void)
{
    int item = 0;
    Stack s(5);

    for ( int i = 0; i < 7; i++ ) {
        s.push(i);
        s.peek(item);
        cout << "Peek at " << item << endl;
    }
    cout << "Popping " << endl;
    for ( int i = 0; i < 7; i++ ) {
        s.pop();
        s.peek(item);
        cout << "Peek at " << item << endl;
    }
    return 0;
}
