#ifndef TIMER_H
#define TIMER_H

#include <Windows.h>

class Timer
{
public:
    Timer();
    Timer(const Timer&) = delete;
    Timer& operator=(const Timer&) = delete;
    ~Timer() = default;

    void      start();
    long long elapsedMilliseconds() const;
    float     elapsedSeconds() const;

private:
    LARGE_INTEGER frequency_;
    LARGE_INTEGER start_;
};

#endif // !TIMER_H
