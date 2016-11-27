#ifndef INTVECTOR_HPP
#define INTVECTOR_HPP

#include <cmath>

class intvector {
public:
    intvector();
    intvector(const intvector& input_vector);
    intvector(int size);
    ~intvector();

    intvector& operator=(const intvector& input_vector);
    int& operator[](const int& index);
    const int& operator[](const int& index) const;
    
    void push_back(int i);
    
    int& at(const int& i);
    int size() const;
    int capacity() const;
    int find(const int& i) const;
private:
    int* vector_pointer;
    int vector_size;
    int vector_capacity;
};

#endif
