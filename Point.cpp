#include "Point.h"

Point::Point() : x(0),y(0) {}

Point::Point(int x, int y) : x(x),y(y) { }

int Point::getX() {
    return x;
}

int Point::getY() {
    return y;
}

bool Point::isAvailable() {
    return true;
}


void Point::setAvailability(bool isAvailable) {

}

bool Point::operator==(const Point &other) const {
    return(x==other.x) && (y==other.y);
}

bool Point::operator<(const Point &other) const {
    if ((x < other.x) ||
        (x == other.x && (y < other.y)))
        return true;
    else
        return false;
}

ostream& operator <<(ostream& os, Point &point) {
    return os << "(" << point.getX() << "," << point.getY() << ")";
}

bool Point::operator!=(const Point &other) const {
    return !this->operator==(other);
}

