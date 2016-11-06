#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "point.hpp"

class Triangle {
public:
    Triangle() : p1(), p2(), p3() {}
    Triangle(Point p1, Point p2, Point p3);

    void set(Point p1, Point p2, Point p3);
    void set_point(unsigned point, Point p);

    double perimeter();
protected:
private:
    Point p1, p2, p3;
};

#endif
