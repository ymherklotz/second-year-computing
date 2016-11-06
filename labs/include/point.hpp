#ifndef POINT_HPP
#define POINT_HPP

#include <string>
#include <sstream>
#include <cmath>

class Point {
public:
    Point() : x(0), y(0), distance(0) {}
    Point(double x, double y);

    void set(double x, double y);
    void set_x(double x);
    void set_y(double y);
    void origin_symmetry();
    void translate(Point p);

    double get_x();
    double get_y();
    double get_distance();
    double get_distance(Point p);

    std::string str();
    
protected:
private:
    double x;
    double y;
    double distance;

    void calc_distance();
};

#endif
