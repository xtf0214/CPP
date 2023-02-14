#include <windows.h>
class stop_watch {
    LARGE_INTEGER freq;
    LARGE_INTEGER begin_time;
    long long elapsed;
    void stop() {
        LARGE_INTEGER end_time;
        QueryPerformanceCounter(&end_time);
        elapsed = (end_time.QuadPart - begin_time.QuadPart) * 1000000 / freq.QuadPart;
    }

  public:
    stop_watch() : elapsed(0) { QueryPerformanceFrequency(&freq); }
    void start() { QueryPerformanceCounter(&begin_time); }
    double elapsed_us() {
        stop();
        return static_cast<double>(elapsed);
    } // 微秒
    double elapsed_ms() {
        stop();
        return elapsed / 1000.0;
    } // 毫秒
    double elapsed_s() {
        stop();
        return elapsed / 1000000.0;
    } // 秒
};