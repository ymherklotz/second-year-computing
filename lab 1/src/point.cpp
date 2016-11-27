#include "../include/point.hpp"

Point::Point(double x, double y) {
    set(x, y);
}

Point::~Point() {
    
}

bool operator<(const Point& p1, const Point& p2) {
    if(p1.distance < p2.distance)
        return true;
    return false;
}

bool operator==(const Point& p1, const Point& p2) {
    if(p1.x == p2.x && p1.y == p2.y)
        return true;
    return false;
}

std::ostream& operator<<(std::ostream& out, const Point& p) {
    return out << p.str();
}

void Point::set(double x, double y) {
    set_x(x);
    set_y(y);
}

void Point::set_x(double x) {
    this->x = x;
    calc_distance();
}

void Point::set_y(double y) {
    this->y = y;
    calc_distance();
}

void Point::origin_symmetry() {
    set(-x, -y);
}

void Point::translate(Point p) {
    set(x+p.x, y+p.y);
}

double Point::get_x() {
    return x;
}

double Point::get_y() {
    return y;
}

double Point::get_distance() {
    return distance;
}

double Point::get_distance(Point p) {
    return sqrt(pow(x-p.x, 2) + pow(y-p.y, 2));
}

std::string Point::str() const {
    std::stringstream ss;
    ss << "(" << x << ", " << y << ")";
    return ss.str();
}

void Point::calc_distance() {
    distance = sqrt(pow(x, 2) + pow(y, 2));
}
