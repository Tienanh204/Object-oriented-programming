#include "Jewelry.h"

Jewelry::Jewelry() {};

Jewelry::Jewelry(const std::string& id, double area, double fee)
    : _id(id), _area(area), _securityFee(fee) {}

// Getters definitions
std::string Jewelry::IDRent() {
    return _id;
}

double Jewelry::AreaRent() {
    return _area;
}

double Jewelry::OtherCosts() {
    return _securityFee;
}

// Setters definitions
void Jewelry::setId(const std::string& id) {
    _id = id;
}

void Jewelry::setArea(double area) {
    _area = area;
}

void Jewelry::setSecurityFee(double fee) {
    _securityFee = fee;
}

double Jewelry::LeaseholdCash() {
    return _area * 560000;
}


double Jewelry::Total() {
    return LeaseholdCash() + OtherCosts();
}

std::string Jewelry::toString() {
    return "Da qui";
}