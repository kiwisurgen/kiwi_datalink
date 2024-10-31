// File: SystemClock.h

#include <chrono>

class SystemClock {
    public:
        using Clock = std::chrono::system_clock;
        using TimePoint = std::chrono::time_point<Clock>;
        using Milliseconds = std::chrono::milliseconds;

        static TimePoint now() {
            return Clock::now();
        }

        static TimePoint addMilliseconds(TimePoint time, Milliseconds milliseconds) {
            return time + milliseconds;
        }
};