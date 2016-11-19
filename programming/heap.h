#include <stdlib.h>
#include <iostream>
#include <vector>
#include <memory>

#include "complete_binary_tree.h"

namespace heap {

using namespace std;

using IntArray = std::vector<int>;

class ArrayHeap {
    public:
        using Ptr = std::shared_ptr<ArrayHeap>;
        ArrayHeap(int max_size) : max_size_(max_size) { }
        int insert(int item) {
            items_.push_back(item);
            _heapify();
            cout << this->print();
            return 0;
        }
        int min() {
            if ( items_.size() == 0 ) {
                throw  runtime_error("Heap is empty");
            }
            return items_[0];
        }
        int size() {
            return items_.size();
        }

        int max_size() {
            return max_size_;
        }
        string print() {
            std::string res;
            for ( auto& p : items_ ) {
                res += to_string(p) + " ";
            }
            res += "\n";
            return res;
        }
    private:
        void _heapify() {
            if ( items_.size() <= 1 ) {
                return;
            }
            uint32_t parent = items_.size() - 1;
            while ( true ) {
                int ret = get_parent<IntArray>(items_, parent, parent);
                if ( ret == -1 ) {
                    break;
                }
                uint32_t left = 0, right = 0;
                get_left_child<IntArray>(items_, parent, left);
                get_right_child<IntArray>(items_, parent, right);
                uint32_t swap_candidate = right;
                if ( (right >= items_.size()) or (items_[right] > items_[left]) ) {
                    swap_candidate = left;
                }
                if ( items_[parent] > items_[swap_candidate] ) {
                    int tmp = items_[swap_candidate];
                    items_[swap_candidate] = items_[parent];
                    items_[parent] = tmp;
                }
            }
        }
        IntArray items_;
        int max_size_;
};

}