#include "Point.h"

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
