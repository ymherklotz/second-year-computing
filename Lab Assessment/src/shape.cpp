#include "shape.hpp"

double Point::distance(Point p) {
    return sqrt(pow(x-p.x, 2) + pow(y-p.y, 2));
}

Triangle::Triangle(Point p1_in, Point p2_in, Point p3_in) : p1(p1_in), p2(p2_in), p3(p3_in) {
    if(!check_valid()) {
        throw std::logic_error("Triangle Error: Couldn't create triangle, invalid coordiantes");
    }
}

double Triangle::get_perimeter() {
    return p1.distance(p2) + p1.distance(p3) + p2.distance(p3);
}

bool Triangle::check_valid() {
    return (p1.distance(p2) < p2.distance(p3) + p1.distance(p3) &&
            p1.distance(p3) < p2.distance(p3) + p1.distance(p2) &&
            p2.distance(p3) < p1.distance(p2) + p1.distance(p3));
}

Circle::Circle(Point centre_in, double radius_in) : centre(centre_in), radius(radius_in) {
    if(radius <= 0) {
        throw std::logic_error("Circle Error: Couldn't create circle with negative or 0 radius");
    }
}

double Circle::get_perimeter() {
    return 2*radius*PI;
}
