#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <cmath>
#include <stdexcept>
#include <cstdio>
#include <sstream>
#include <string>

// abstract class shape
class Shape {
public:
    virtual double get_perimeter()=0;
};

class Point {
public:
    Point(double x_in, double y_in) : x(x_in), y(y_in) {}

    friend std::ostream& operator<<(std::ostream& out, const Point& p) {
        std::stringstream ss;
        ss << "(" << p.x << ", " << p.y << ")";
        out << ss.str();
        return out;
    }

    double distance(Point p);
private:
    double x, y;
};

class Triangle : public Shape {
public:
    Triangle(Point p1_in, Point p2_in, Point p3_in);

    friend std::ostream& operator<<(std::ostream& out, const Triangle& t) {
        std::stringstream ss;
        ss << t.p1 << " " << t.p2 << " " << t.p3;
        out << ss.str();
        return out;
    }

    double get_perimeter();
private:
    Point p1, p2, p3;

    bool check_valid();
};

class Circle : public Shape {
public:
    Circle(Point centre_in, double radius_in);

    friend std::ostream& operator<<(std::ostream& out, const Circle& c) {
        std::stringstream ss;
        ss << c.centre << ", " << c.radius;
        out << ss.str();
        return out;
    }

    double get_perimeter();
private:
    const double PI = 3.14;
    Point centre;
    double radius;
};

#endif
