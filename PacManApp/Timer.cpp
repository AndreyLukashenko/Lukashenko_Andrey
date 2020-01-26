#include "Timer.hpp"

Timer::Timer()
{
    QueryPerformanceFrequency(&frequency_);
}


void Timer::start() 
{
    QueryPerformanceCounter(&start_);
}


long long Timer::elapsedMilliseconds() const 
{
    LARGE_INTEGER now;
    QueryPerformanceCounter(&now);
    return (((now.QuadPart - start_.QuadPart) * 1000) / frequency_.QuadPart);
}


float Timer::elapsedSeconds() const 
{
    return static_cast<float>(elapsedMilliseconds()) / 1000.0f;
}