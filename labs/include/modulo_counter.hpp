#ifndef MODULO_COUNTER_HPP
#define MODULO_COUNTER_HPP

#include "counter.hpp"

class ModuloCounter : public Counter {
public:
    ModuloCounter(int m=0);
    bool increment();
private:
    int modulo;
};

#endif
