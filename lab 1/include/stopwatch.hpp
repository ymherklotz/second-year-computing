#ifndef STOPWATCH_HPP
#define STOPWATCH_HPP

#include "counter.hpp"
#include "modulo_counter.hpp"

#include <ostream>

class Stopwatch {
public:
    Stopwatch();
    void tick();
    void reset();

    friend std::ostream& operator<<(std::ostream& out, const Stopwatch& sw);
private:
    Counter hours;
    ModuloCounter minutes;
    ModuloCounter seconds;
};

#endif
