#include "lockdb.hpp"

#include <iostream>

using namespace std;

bool update_db(int data);
void write_db(int data);

int main(int argc, char* argv[]) {
    try {
        update_db(10);
    } catch(exception e) {
        cout << "exception occured" << endl;
    }
    return 0;
}

bool update_db(int data) {
    bool exit_code;
    Lockdb ldb;

    if(ldb.get_status()) {
        cout << "doing some operations" << endl;
        write_db(data);
        exit_code = true;
    } else {
        exit_code = false;
    }

    return exit_code;
}

void write_db(int data) {
    // do something with data
    throw exception();
}
