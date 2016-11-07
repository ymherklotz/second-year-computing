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
    return p1.get_distance(p2) + p1.get_distance(p3) + p2.get_distance(p3);
}

void Triangle::translate(Point p) {
    p1.set(p1.get_x()+p.get_x(), p1.get_y()+p.get_y());
    p2.set(p2.get_x()+p.get_x(), p2.get_y()+p.get_y());
    p3.set(p3.get_x()+p.get_x(), p3.get_y()+p.get_y());
}
