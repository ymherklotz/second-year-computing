#include "../include/triangle.hpp"

Triangle::Triangle(Point p1, Point p2, Point p3) {
    set(p1, p2, p3);
}

void Triangle::set(Point p1, Point p2, Point p3) {
    this->p1 = p1;
    this->p2 = p2;
    this->p3 = p3;
}

void Triangle::set_point(unsigned point, Point p) {
    if(point == 1)
        p1 = p;
    else if(point == 2)
        p2 = p;
    else if(point == 3)
        p3 = p;
}

double Triangle::perimeter() {
    return 0;
}
