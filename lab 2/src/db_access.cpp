/*#include <iostream>
#include <fstream>

using namespace std;

void write_db(int data) {
    // do some work here
    // throw exception();
}

bool update_db(int data) {
    bool exit_code;
    ifstream infile(".lockdb");

    if(infile.is_open()) {
        cout << "resource is busy" << endl;
        infile.close();
        exit_code = false;
    } else {
        ofstream outfile(".lockdb");

        if(!outfile.is_open()) {
            throw runtime_error("couldn't lock resource");
        }

        cout << "resource is locked" << endl;
        outfile.close();
        cout << "doing some operations" << endl;
        write_db(data);
        remove(".lockdb");
        cout << "resource is unlocked" << endl;
        exit_code = true;
    }

    return exit_code;
}

int main(int argc, char* argv[]) {
    try {
        update_db(10);
    } catch(exception e) {
        cout << "exception occured" << endl;
    }

    return 0;
}*/
