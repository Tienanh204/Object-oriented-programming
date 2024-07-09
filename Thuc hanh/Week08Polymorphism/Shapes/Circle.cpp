#include "Circle.h"
#include"IShape.h"

//---Circle
Circle::Circle() {
    _radius = 0;
}
Circle::Circle(double radius) {
    _radius = radius;
}
void Circle::setRadius(double radius) {
    _radius = radius;
}
double Circle::getRadius() {
    return _radius;
}
double Circle::area() {
    return _radius * _radius * 3;
}
double Circle::perimeter() {
    return _radius * 2 * 3;
}
std::string Circle::toString() {
    return "Circle r=" + std::to_string((int)_radius);
}

