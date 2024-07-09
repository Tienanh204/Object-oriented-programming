#include "Food.h"

Food::Food() {};

Food::Food(const std::string& id, double area, double coldStorage)
    : _id(id), _area(area), _coldStorage(coldStorage) {}

// Getters definitions
std::string Food::IDRent() {
    return _id;
}

double Food::AreaRent() {
    return _area;
}

// Setters definitions
void Food::setId(const std::string& id) {
    _id = id;
}

void Food::setArea(double area) {
    _area = area;
}

void Food::setColdStorage(double coldStorage) {
    _coldStorage = coldStorage;
}

double Food::LeaseholdCash() {
    return _area * 560000;
}
double Food::OtherCosts() {
    return _coldStorage;
}
double Food::Total() {
    return LeaseholdCash() + OtherCosts();
}

std::string Food::toString() {
    return "Thuc pham";
}