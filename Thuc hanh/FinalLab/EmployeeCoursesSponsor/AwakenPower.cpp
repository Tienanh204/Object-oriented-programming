#include "AwakenPower.h"

AwakenPower::AwakenPower() {};
AwakenPower::AwakenPower(string name, string email, string startDate, double cost) : _name(name), _email(email), _startDate(startDate), _cost(cost) {}

// Getter and Setter methods
string AwakenPower:: getName()  {
    return _name;
}

void AwakenPower::setName(string name) {
    _name = name;
}

string AwakenPower::getEmail()  {
    return _email;
}

void AwakenPower::setEmail(string email) {
    _email = email;
}

string AwakenPower::getStartDate()  {
    return _startDate;
}

void AwakenPower::setStartDate(string startDate) {
    _startDate = startDate;
}

double AwakenPower::getCost()  {
    return _cost;
}

void AwakenPower:: setCost(double cost) {
    _cost = cost;
}

string  AwakenPower::typePersion() {
    return "AwakenPower";
}
string  AwakenPower::counreses() {
    return "Awaken your power";
}
double  AwakenPower::help() {
    return 17;
}
double  AwakenPower::total() {
    return getCost() + help();
}
string  AwakenPower::toString() {
    return "Awaken your power";
}