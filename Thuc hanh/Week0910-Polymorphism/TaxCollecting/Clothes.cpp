#include "Clothes.h"

Clothes::Clothes() {};

Clothes::Clothes(const std::string& id, double area)
    : _id(id), _area(area) {}

// Getters definitions
std::string Clothes::IDRent() {
    return _id;
}

double Clothes::AreaRent() {
    return _area;
}

// Setters definitions
void Clothes::setId(const std::string& id) {
    _id = id;
}

void Clothes::setArea(double area) {
    _area = area;
}

double Clothes::LeaseholdCash() {
    return _area * 560000;
}
double Clothes::OtherCosts() {
    return 0;
}
double Clothes::Total() {
    return LeaseholdCash() + OtherCosts();
}

std::string Clothes::toString() {
    return "Quan ao";
}