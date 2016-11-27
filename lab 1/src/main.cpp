#include <iostream>
#include <vector>

#include "../include/rcl_circuit.hpp"

using namespace std;

int main(int argc, char* argv[]) {
    (void)argc;
    (void)argv;

    vector<component*> circuit;

    component* tmp_id;

    char dc;
    double tmp_rcl;
    int n_devices;

    cout << "number of devices = ";
    cin >> n_devices;

    for(int i = 0; i < n_devices; ++i) {
        cout << "device choice (r/c/l) = ";
        cin >> dc;

        if(dc == 'c') {
            cout << "capacitance (F) = ";
            cin >> tmp_rcl;
            tmp_id = new capacitor(tmp_rcl);
        } else if(dc == 'l') {
            cout << "inductance (H) = ";
            cin >> tmp_rcl;
            tmp_id = new inductor(tmp_rcl);
        } else {
            cout << "resistance (Ohm) = ";
            cin >> tmp_rcl;
            tmp_id = new resistor(tmp_rcl);
        }

        circuit.push_back(tmp_id);
    }

    double f;
    cout << "frequency = ";
    cin >> f;

    for(int i = 0; i < n_devices; ++i) {
        cout << "impedance " << i+1 << ": ";
        cout << circuit[i]->get_impedance(f*6.28) << " Ohms";
        cout << endl;
    }

    for(int i = 0; i < n_devices; ++i) {
        delete circuit[i];
    }

    return 0;
}
