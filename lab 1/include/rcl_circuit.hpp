#ifndef RCL_CIRCUIT_HPP
#define RCL_CIRCUIT_HPP

#include <complex>

class component {
public:
    virtual std::complex<double> get_impedance(double omega) =0;
    virtual ~component() {}
};

class resistor : public component {
public:
    resistor(double r = 0);
    std::complex<double> get_impedance(double omega);
private:
    double resistance;
};

class capacitor : public component {
public:
    capacitor(double c = 0);
    std::complex<double> get_impedance(double omega);
private:
    double capacitance;
};

class inductor : public component {
public:
    inductor(double l = 0);
    std::complex<double> get_impedance(double omega);
private:
    double inductance;
};

#endif
