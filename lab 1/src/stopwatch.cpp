#include "../include/stopwatch.hpp"

Stopwatch::Stopwatch() : hours(), minutes(60), seconds(60) {}

void Stopwatch::reset() {
    hours.reset();
    minutes.reset();
    seconds.reset();
}

void Stopwatch::tick() {
    if(seconds.increment())
        if(minutes.increment())
            hours.increment();
}

std::ostream& operator<<(std::ostream& out, const Stopwatch& sw) {
    return out << sw.hours << ":" << sw.minutes << ":" << sw.seconds;
}
