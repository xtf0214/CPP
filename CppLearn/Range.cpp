/**
 * @file    :   Range
 * @author  :   Tanphoon
 * @date    :   2024/05/30 00:21
 * @version :   2024/05/30 00:21
 */
#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>
using namespace std;

struct Range {
    struct iter {
        using value_type = size_t;
        using reference = size_t &;
        using pointer = size_t *;
        using difference_type = int64_t;
        using iterator_category = std::bidirectional_iterator_tag;
        value_type _val;
        iter(value_type val) : _val(val) {}
        iter &operator++() { return ++_val, *this; }
        iter &operator--() { return --_val, *this; }
        iter operator++(int) { return iter(_val++); }
        iter operator--(int) { return iter(_val--); }
        friend bool operator!=(const iter &lhs, const iter &rhs) { return lhs._val != rhs._val; }
        reference operator*() { return _val; }
        // 能够使用 lower_bound 和 upper_bound 二分查找
        friend difference_type operator-(const iter &lhs, const iter &rhs) {
            return rhs._val - lhs._val;
        }
        iter &operator+=(int64_t n) { return _val += n, *this; }
    };
    size_t _begin = 0, _end = 0;
    Range() {}
    Range(size_t begin, size_t end) : _begin(begin), _end(end) {}
    const iter begin() const { return iter(_begin); }
    const iter end() const { return iter(_end); }
};

int main() {
    Range v(1, 10);
    for (int i : v)
        cout << i << ' ';
    cout << '\n';
    cout << *lower_bound(v.begin(), v.end(), 25, [](int x, int v) { return x * x <= v; }) << '\n';
}