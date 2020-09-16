#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include "utils.h"
#include "timer.h"
#include "utils.h"

using namespace std;

/*
  https://leetcode.com/discuss/interview-question/634115/Google-or-Onsite-or-Merge-Intervals-With-Labels
  Given a set of inputs which represents [from, to, comment] in google docs.
  Transform the input with overlapping offsets & unique comments to non overlapping offsets and duplicate comments.
  
  Example 1:
  
  Input: 
  (0, 3): A
  (2, 4): B
  (3, 4): D
  (5, 6): C
  
  Output:
  (0, 2): [A]
  (2, 3): [A, B]
  (3, 4): [B]
  (5, 6): [C]
 */
struct Entry {
  int from;
  int to;
  vector<string> comments;

  Entry(int f, int t, const vector<string>& c) : from(f), to(f), comments{c} { }

  bool operator<(const Entry& other) {
    if (from == other.from) {
      return to < other.to;
    }
    return from < other.from;
  }

  bool valid() {
    return from < to;
  }

  bool is_overlapping(const Entry& e1, const Entry& e2) {
    return e1.to >= e2.from;
  }

  vector<Entry> merge(const Entry& e1, const Entry& e2) {
    Entry one(e1.from, min(e1.to, e2.from), {e1.comments});

    Entry two(min(e1.to, e2.from), e2.to, e1.comments);
    two.comments.insert(two.comments.end(), e2.comments.begin(), e2.comments.end());

    Entry three(max(e1.to, e2.from), e2.to, {e2.comments});

    vector<Entry> res;
    if (one.valid()) {
      res.push_back(one);
    }

    if (two.valid()) {
      res.push_back(two);
    }

    if (three.valid()) {
      res.push_back(three);
    }
    return res;
  }

  string to_string() {
    return std::to_string(from) + ":" + std::to_string(to);
  }
};

void merge_intervals(vector<Entry>& intervals) {
  sort(intervals.begin(), intervals.end());

}

int main(void) {
  vector<Entry> intervals{Entry(0, 3, {"A"}), Entry(2,3, {"B"}), Entry(5,6, {"C"})};

  merge_intervals(intervals);

  return 0;
}