#ifndef POINT_HPP
#define POINT_HPP

#include <string>
#include <sstream>
#include <cmath>

class Point {
public:
    Point() : x(0), y(0), distance(0) {}
    Point(double x, double y);
    ~Point();

    friend bool operator<(const Point& p1, const Point& p2);
    inline friend bool operator>(const Point& p1, const Point& p2) {
        return p2 < p1;
    }
    inline friend bool operator>=(const Point& p1, const Point& p2) {
        return !(p1 < p2);
    }
    inline friend bool operator<=(const Point& p1, const Point& p2) {
        return !(p1 > p2);
    }
    friend bool operator==(const Point& p1, const Point& p2);
    friend std::ostream& operator<<(std::ostream& out, const Point& p);
    
    void set(double x, double y);
    void set_x(double x);
    void set_y(double y);
    void origin_symmetry();
    void translate(Point p);

    double get_x();
    double get_y();
    double get_distance();
    double get_distance(Point p);

    std::string str() const;
    
protected:
private:
    double x;
    double y;
    double distance;

    void calc_distance();
};

#endif
