#include "lockdb.hpp"

#include <fstream>
#include <iostream>

using namespace std;

Lockdb::Lockdb() {
    ifstream infile(".lockdb");
    if(infile.is_open()) {
        status = false;
        cout << "resouce is busy" << endl;
    } else {
        ofstream outfile(".lockdb");

        if(!outfile.is_open()) {
            status = false;
            throw runtime_error("couldn't lock resource");
        }

        status = true;
        cout << "resource is locked" << endl;
    }
}

Lockdb::~Lockdb() {
    cout << "destructor" << endl;
    if(status) {
        remove(".lockdb");
        cout << "resource unlocked" << endl;
    }
}

bool Lockdb::get_status() {
    return status;
}
