#pragma once

#include <ctime>

namespace utils
{

class Timer
{
private:
    clock_t m_startTicks;
    clock_t m_pausedTicks;

    bool m_isPaused;
    bool m_isStarted;

public:
    Timer() : m_startTicks(0), m_pausedTicks(0), m_isPaused(false), m_isStarted(false) {}

    void start();
    void clear();
    void pause();
    void restart();

    clock_t getTicks() const;

    inline bool isStarted() const;
    inline bool isPaused() const;
    bool hasElapsed(clock_t ms) const;
};

} // namespace utils
