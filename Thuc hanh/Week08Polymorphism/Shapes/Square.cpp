#include "Square.h"
#include"IShape.h"

//---Square
Square::Square() {
    _a = 0;
}
Square::Square(double a) {
    _a = a;
}
void Square::setA(double a) {
    _a = a;
}
double Square::getA() {
    return _a;
}
double Square::area() {
    return _a * _a;
}
double Square::perimeter() {
    return _a * 4;
}
std::string Square::toString() {
    return "Square a=" + std::to_string((int)_a);
}