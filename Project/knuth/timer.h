#include <windows.h>
#include <iostream>
double getTime()
{
    LARGE_INTEGER t, tc;
    QueryPerformanceFrequency(&tc);
    QueryPerformanceCounter(&t);
    return (double)(t.QuadPart) / (double)tc.QuadPart;
}