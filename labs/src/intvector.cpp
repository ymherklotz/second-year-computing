#include "../include/intvector.hpp"

intvector::intvector() {
    vector_pointer = new int[1];
    vector_size = 0;
    vector_capacity = 1;
}

intvector::intvector(const intvector& input_vector) {
    vector_pointer = new int[1];
    vector_size = 0;
    vector_capacity = 1;
    *this = input_vector;
}

intvector::intvector(int size) {
    vector_size = size;
    vector_capacity = pow(2, ceil(log2(size+1)));
    vector_pointer = new int[vector_size];

    for(int i = 0; i < vector_size; ++i) {
        vector_pointer[i] = 0;
    }
}

intvector::~intvector() {
    delete[] vector_pointer;
}

intvector& intvector::operator=(const intvector& input_vector) {
    delete[] vector_pointer;
    vector_size = input_vector.size();
    vector_capacity = input_vector.capacity();
    vector_pointer = new int[vector_capacity];
    
    for(int i = 0; i < input_vector.size(); ++i) {
        vector_pointer[i] = input_vector[i];
    }

    return *this;
}

int& intvector::operator[](const int& index) {
    if(index < vector_size)
        return vector_pointer[index];
    return vector_size;
}

const int& intvector::operator[](const int& index) const {
    if(index < vector_size)
        return vector_pointer[index];
    return vector_size;
}

void intvector::push_back(int i) {
    if(vector_size >= vector_capacity) {
        intvector tmp(vector_size);
        for(int j = 0; j < vector_size; ++j) {
            tmp[j] = vector_pointer[j];
        }
        *this = tmp;
    }
    vector_pointer[vector_size] = i;
    ++vector_size;
}

int& intvector::at(const int& i) {
    if(i < vector_size)
        return vector_pointer[i];
    return vector_size;
}

int intvector::size() const {
    return vector_size;
}

int intvector::capacity() const {
    return vector_capacity;
}

int intvector::find(const int& i) const {
    for(int j = 0; j < vector_size; ++j) {
        if(vector_pointer[j] == i) {
            return j;
        }
    }
    return -1;
}
