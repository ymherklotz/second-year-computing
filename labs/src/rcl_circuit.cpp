#include "../include/rcl_circuit.hpp"

resistor::resistor(double r) : resistance(r) {}

std::complex<double> resistor::get_impedance(double omega) {
    (void) omega;
    std::complex<double> impedance(resistance);
    return impedance;
}

capacitor::capacitor(double c) : capacitance(c) {}

std::complex<double> capacitor::get_impedance(double omega) {
    std::complex<double> impedance(0, -1/(omega*capacitance));
    return impedance;
}

inductor::inductor(double l) : inductance(l) {}

std::complex<double> inductor::get_impedance(double omega) {
    std::complex<double> impedance(0, omega*inductance);
    return impedance;
}
