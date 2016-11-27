#include "../include/counter.hpp"

Counter::Counter() : count(0) {}

void Counter::increment() {
    count++;
}

void Counter::reset() {
    count = 0;
}

int Counter::get_count() const {
    return count;
}


std::ostream& operator<<(std::ostream& out, const Counter& c) {
    return out << c.count;
}
