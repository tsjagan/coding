#ifndef __RANGE_H_
#define __RANGE_H_

#include <sstream>

template <typename T>
class Range {
    public:
        Range(const T& start, const T& end) :
              start_(start), end_(end) { }

        T start() const {
            return start_;
        }

        T end() const {
            return end_;
        }

        bool operator==(const Range& other) const {
            if ( other.start_ != this->start_ ) {
                return false;
            }
            if ( other.end_ != this->end_ ) {
                return false;
            }
            return true;
        }

        bool overlap(const Range& other) const {
            if ( *this == other ) {
                return true;
            }
            if ( other.contains(*this) == true ) {
                return true;
            }
            if ( contains(other) == true ) {
                return true;
            }
            if ( left_overlap(other) == true ) {
                return true;
            }
            if ( right_overlap(other) == true ) {
                return true;
            }
            return false;
        }

        Range& operator+=(const Range& other) {
            if ( *this == other ) {
                return *this;
            }
            if ( other.contains(*this) == true ) {
                this->start_ = other.start_;
                this->end_ = other.end_;
            }
            if ( contains(other) == true ) {
                return *this;
            }
            if ( left_overlap(other) == true ) {
                this->start_ = other.start_;
                return *this;
            }
            if ( right_overlap(other) == true ) {
                this->end_ = other.end_;
                return *this;
            }
            return *this;
        }

        bool contains(const Range& other) const {
            if ( other.start_ >= start_ and other.end_ <= end_ ) {
                return true;
            }
            return false;
        }

        bool left_overlap(const Range& other) const {
            if ( other.start_ < start_ and
                 (other.end_ >= start_ and other.end_ <= end_) ) {
                return true;
            }
            return false;
        }

        bool right_overlap(const Range& other) const {
            if ( other.end_ > end_ and
                 (other.start_ >= start_ and other.start_ <= end_) ) {
                return true;
            }
            return false;
        }
        std::string to_string() const {
            std::stringstream ss;
            ss << "Start : " << start_;
            ss << std::endl;
            ss << "End : " << end_;
            ss << std::endl;
            return ss.str();
        }
    private:
        T start_;
        T end_;
};

#endif
