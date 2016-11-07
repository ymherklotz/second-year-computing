#ifndef COUNTER_HPP
#define COUNTER_HPP

#include <ostream>

class Counter {
public:
    Counter();
    void increment();
    void reset();
    int get_count() const;

    friend std::ostream& operator<<(std::ostream& out, const Counter& c);
    
protected:
    int count;
};

#endif
