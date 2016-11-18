#include <stdlib.h>
#include <iostream>

using namespace std;

class Stack {
    public:
        Stack(int size) : top_(-1), size_(size), max_top_(-1) {
            this->stack_ = new int[size];
            this->max_stack_ = new int[size];
        }
        ~Stack() {
            if ( this->stack_ != nullptr ) {
                delete this->stack_;
            }
            if ( this->max_stack_ != nullptr ) {
                delete this->max_stack_;
            }
        }
        int push(int item) {
            if ( this->top_ == this->size_ ) {
                return -1;
            }
            this->stack_[++this->top_] = item;
            if ( max_top_ == -1 or item > max_stack_[max_top_] ) {
                max_stack_[++max_top_] = item;
            }
            return 0;
        }
        void pop() {
            if ( this->top_ == -1 ) {
                cout << "Stack is empty" << endl;
                return;
            }
            if ( max_top_ != -1 and max_stack_[max_top_] == stack_[top_]) {
                max_top_--;
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
        int peekMax(int& item) {
            if ( max_top_ == -1 ) {
                cout << "Stack is empty" << endl;
                return -1;
            }
            return max_stack_[max_top_];
        }
    private:
        int *stack_;
        uint32_t top_;
        uint32_t size_;
        int *max_stack_;
        uint32_t max_top_;
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
