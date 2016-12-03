#include "shape.hpp"

#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include <stdexcept>

typedef Shape* shape_ptr;

using namespace std;

int main(int argc, char* argv[]) {
    // streams that open input files
    ifstream t_file, c_file;
    // sotres tmp variables in arrays
    double x_tmp[3], y_tmp[3];
    // radius of circle
    double radius_tmp;
    // shape pointer added to the vector
    shape_ptr shape_tmp;

    // lists in which the triangles and circles are stored
    list<Triangle> triangle_list;
    list<Circle> circle_list;

    // vector suitable for triangle and circle pointers
    vector<shape_ptr> shape_vector;

    // try opening the files
    try {
        t_file.open(argv[1]);
        c_file.open(argv[2]);
        if(!t_file.is_open() || !c_file.is_open()) {
            throw logic_error("Error opening files");
        }
    } catch(logic_error e) {
        cout << e.what() << endl;
        exit(EXIT_FAILURE);
    }

    // read from triangle file
    while(t_file >> x_tmp[0] >> y_tmp[0] >> x_tmp[1] >> y_tmp[1] >> x_tmp[2] >> y_tmp[2]) {
        Point p1_tmp(x_tmp[0], y_tmp[0]);
        Point p2_tmp(x_tmp[1], y_tmp[1]);
        Point p3_tmp(x_tmp[2], y_tmp[2]);

        try {
            Triangle triangle_tmp(p1_tmp, p2_tmp, p3_tmp);
            triangle_list.push_back(triangle_tmp);
        } catch(logic_error e) {
            cout << e.what() << endl;
            t_file.close();
            c_file.close();
            exit(EXIT_FAILURE);
        }
    }

    // read from circle file
    while(c_file >> x_tmp[0] >> y_tmp[0] >> radius_tmp) {
        Point p_tmp(x_tmp[0], y_tmp[0]);

        try {
            Circle circle_tmp(p_tmp, radius_tmp);
            circle_list.push_back(circle_tmp);
        } catch(logic_error e) {
            cout << e.what() << endl;
            t_file.close();
            c_file.close();
            exit(EXIT_FAILURE);
        }
    }

/*
    // prints out the triangles
    for(list<Triangle>::iterator it = triangle_list.begin(); it != triangle_list.end(); ++it) {
        cout << *it << endl;
    }

    // prints out the cirlces
    for(list<Circle>::iterator it = circle_list.begin(); it != circle_list.end(); ++it) {
        cout << *it << endl;
    }
*/

    // adding Triangles and Circles to vector of Shapes
    for(list<Triangle>::iterator it = triangle_list.begin(); it != triangle_list.end(); ++it) {
        shape_tmp = &*it;
        shape_vector.push_back(shape_tmp);
    }

    for(list<Circle>::iterator it = circle_list.begin(); it != circle_list.end(); ++it) {
        shape_tmp = &*it;
        shape_vector.push_back(shape_tmp);
    }

    // printing perimeters for all shapes
    for(vector<shape_ptr>::iterator it = shape_vector.begin(); it != shape_vector.end(); ++it) {
        cout << (*it)->get_perimeter() << endl;
    }

    // close everything
    t_file.close();
    c_file.close();

    return 0;
}
