/**
 * @file    :   for_range
 * @author  :   Tanphoon
 * @date    :   2023/02/28 17:34
 * @version :   2023/02/28 17:34
 */
#include <bits/stdc++.h>
using namespace std;

class FakeIter {
    typedef long T;

  public:
    explicit FakeIter(T val) : value_(val) {}
    bool operator!=(const FakeIter &other) const { return GetValue() != other.GetValue(); }
    T operator*() const { return GetValue(); }
    const FakeIter &operator++() {
        ++value_;
        return *this;
    }

  private:
    T GetValue() const { return value_; }
    T value_;
};
class Range {
    typedef long T;

  public:
    Range(T begin_v, T end_v) : begin_value_(begin_v), end_value_(end_v) {}
    FakeIter begin() const { return FakeIter(begin_value_); }
    FakeIter end() const { return FakeIter(end_value_); }

  private:
    T begin_value_;
    T end_value_;
};

int main() {
    for (int i : Range(0, 5))
        cout << i << " ";
    cout << endl;
    return 0;
}