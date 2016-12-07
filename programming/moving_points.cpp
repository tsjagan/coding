#include <iostream>
#include <stdlib.h>
#include <vector>
#include <sstream>
#include <cfloat>

using namespace std;

using Position = double;
using Distance = double;
using BallId = int;
using Colliders = std::pair<BallId, BallId>;

enum Direction {
    LEFT = 0,
    RIGHT = 1
};

class FallException: public exception {
    virtual const char* what() const throw() {
        return "Ball fell of the edge";
    }
};

class Ball {
    public:
        Ball(const Position& p, const Direction& d) :
             current_(p), direction_(d) { }

        std::string ToStr() {
            std::stringstream ss;
            ss << "Position : "  << current_;
            ss << ", Direction : "  << direction_;
            return ss.str();
        }
        Position& current() {
            return this->current_;
        }
        Direction& direction() {
            return this->direction_;
        }
        void change_direction() {
            if ( direction_ == LEFT ) {
                direction_ = RIGHT;
            } else {
                direction_ = LEFT;
            }
        }
    private:
        Position current_; 
        Direction direction_;
};

class Table {
    public:
        Table(double left, double right) :
             left_(left), right_(right) {
        }

        size_t add_ball(const Ball& b) {
            this->balls_.push_back(b);
            return balls_.size();
        }

        Ball get_ball(BallId id) {
            return this->balls_[id];
        }
        Distance move(BallId id, double count) {
            if ( balls_[id].direction() == LEFT ) {
                return this->move_left(id, count);
            }
            return this->move_right(id, count);
        }
        Distance move_left(BallId id, double count) {
            Ball& b = balls_[id];
            b.current() -= count;
            //cout << "Moved ball : " << id << " to " << b.current() << endl;
            return count;
        }
        Distance move_right(int id, double count) {
            Ball& b = balls_[id];
            b.current() += count;
            //cout << "Moved ball : " << id << " to " << b.current() << endl;
            return count;
        }
        Distance solve() {
            Distance total = 0;
            while ( this->balls_.size() > 0 ) {
                Colliders col;
                auto d = this->next_collision(col);
                this->move(d, col);
                cout << this->ToStr() << endl;
                total += d;
            }
            return total;
        }
        void move(double count, Colliders& col) {
            auto s = balls_.size();
            for ( int i = 0; i < s; i++ ) {
                this->move(i, count);
            }
            if ( col.first == -1 ) {
                balls_.erase(balls_.begin());
            } else if ( col.first == balls_.size() ) {
                balls_.erase(balls_.end()-1);
            } else {
                balls_[col.first].change_direction();
                balls_[col.second].change_direction();
            }
        }
        Distance next_collision(Colliders& col) {
            Distance min_d(DBL_MAX);
            for ( int i = -1; i < int(balls_.size()); i++ ) {
                Distance d(0.0);
                if ( i == -1 and balls_[0].direction() == LEFT ) {
                    d = _collision_distance(balls_[0], left_);
                } else if ( i == balls_.size()-1 and
                            balls_[0].direction() == RIGHT ) {
                    d = _collision_distance(balls_[i], right_);
                } else {
                    d = _collision_distance(balls_[i], balls_[i+1]);
                }
                if ( d < min_d ) {
                    if ( i == -1 ) {
                        col = std::make_pair(-1, -1);
                    } else if ( i == balls_.size()-1 ) {
                        col = std::make_pair(balls_.size(), balls_.size());
                    } else {
                        col = std::make_pair(i, i+1);
                    }
                    min_d = d;
                }
            }
            cout << "Colliders are  :" << col.first << " and " << col.second << endl;
            cout << "Collision distance is :" << min_d << endl;
            return min_d;
        }
        std::string ToStr() {
            std::stringstream ss;
            ss << "Table = " << left_ << "----" << right_ << endl;
            for ( auto& b : this->balls_ ) {
                ss << b.ToStr() << endl;
            }
            return ss.str();
        }
    private:
        Distance _collision_distance(Ball& ball, Position& p) {
            if ( ball.current() > p ) {
                return (ball.current() - p);
            }
            return (p - ball.current());
        }
        Distance _collision_distance(Ball& one, Ball& two) {
            if ( one.direction() == RIGHT and  two.direction() == LEFT ) {
               return (two.current() - one.current())/2;
            }
            return Distance(DBL_MAX);
        }
        std::vector<Ball> balls_;
        Position left_, right_;
};

int main(void)
{
    Table table(10, 50);

    table.add_ball(Ball(10, LEFT));
    table.add_ball(Ball(15, RIGHT));
    table.add_ball(Ball(20, LEFT));
    table.add_ball(Ball(30, LEFT));
    table.add_ball(Ball(40, LEFT));
    cout << table.ToStr() << endl;

    table.solve();

    return 0;
}
