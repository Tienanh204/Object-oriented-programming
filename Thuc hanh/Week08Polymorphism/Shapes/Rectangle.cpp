#include "Rectangle.h"
#include"IShape.h"

//--Rectangle
Rectangle::Rectangle() {
    _width = 0;
    _height = 0;
}
Rectangle::Rectangle(double width, double height) {
    _width = width;
    _height = height;
}
void Rectangle::setWidth(double width) {
    _width = width;
}
void Rectangle::setHeight(double height) {
    _height = height;
}
double Rectangle::getWidth() {
    return _width;
}
double Rectangle::getHeight() {
    return _height;
}
double Rectangle::area() {
    return _width * _height;
}
double Rectangle::perimeter() {
    return (_width + _height) * 2;
}
std::string Rectangle::toString() {
    return "Rectangle w=" + std::to_string((int)_width) + ", h=" + std::to_string((int)_height);
}