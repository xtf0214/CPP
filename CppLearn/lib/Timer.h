#pragma once
#include <ctime>
class Timer {
    struct time {
        double total, once;
    };
    unsigned long long last_time, total;

  public:
    void start() {
        last_time = clock();
        total = 0;
    }
    time get() {
        unsigned long long now_time = clock();
        unsigned long long once = now_time - last_time;
        total += once;
        last_time = now_time;
        return time{total / 1000.0, once / 1000.0};
    }
};