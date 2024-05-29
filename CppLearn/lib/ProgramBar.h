#pragma once

#include <iomanip>
#include <iostream>
#include <string>

#define GREEN "\033[0;32m"
#define CLEAR "\033[0m"

class ProgressBar {
    int64_t begin, end;
    uint64_t begin_time;

  public:
    ProgressBar(int64_t begin, int64_t end) : begin(begin), end(end), begin_time(clock()) {
        // CONSOLE_CURSOR_INFO cursor_info = {20, false}; // 隐藏光标
        // SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
    }
    void operator()(int64_t now) {
        int64_t cur = now - begin + 1, len = end - begin + 1;
        if (len > 1009 && cur % (len / 1009) != 0 && now != end) // 进度条只跑1009次，质数次
            return;
        uint64_t now_time = clock();
        double times = (now_time - begin_time) / 1000.0;
        double rtimes = times * (end - now) / cur;
        uint64_t Min = times / 60, rMin = rtimes / 60;
        double Sec = times - Min * 60, rSec = rtimes - rMin * 60;
        printf("\r");
        printf("%s%3llu%%%s", GREEN, cur * 100 / len, CLEAR); // 百分比
        // printf("|%s%s|", std::string(cur * 10 / len, '>').c_str(),
        //        std::string((end - now) * 10 / len, '=').c_str());
        printf("[%s%llu/%llu%s]", GREEN, cur, len, CLEAR); // 迭代次数
        printf("[%s%02llu:%04.1lf<%02llu:%04.1lf%s]", GREEN, Min, Sec, rMin, rSec, CLEAR); // 时间
        if (now == end)
            printf("\n");
    }
};