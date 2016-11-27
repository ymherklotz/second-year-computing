#include "../include/modulo_counter.hpp"

ModuloCounter::ModuloCounter(int m /* = 0 */) : Counter(), modulo(m) {}

bool ModuloCounter::increment() {
    count++;
    if((modulo > 0) && (count >= modulo)) {
        reset();
        return true;
    }
    return false;
}
