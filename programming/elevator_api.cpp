#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

enum RequestType {
    GETIN = 0,
    GETOUT = 1
};
using Level = int;
using Request = std::pair<Level, RequestType>;
using Requests = vector<Level>;

class Elevetor {
    public:
        Elevetor() : curr_(0) { }
        void add_request(Level level) {
            this->requests_.push_back(level);
        }

        Level serve() {
            while ( requests_.size() > 0 ) {
                this->next();
            }
        }
        Level next() {
            auto next = _schedule_request();
            this->curr_ = next;            
            this->requests_.erase(next);
        }
        Level _schedule_request() {
            return requests_.begin();
        }
        Level current() {
            return curr_;
        }
    private:
        Level curr_;
        Requests requests_;
};

int main(void)
{
}