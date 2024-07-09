#include "SelfDevelopment.h"
#include "FinancialFreedom.h"

SelfDevelopment::SelfDevelopment() {};
SelfDevelopment::SelfDevelopment(string name, string email, string startDate, double cost) : _name(name), _email(email), _startDate(startDate), _cost(cost) {}

// Getter and Setter methods
string SelfDevelopment::getName()  {
    return _name;
}

void SelfDevelopment::setName(string name) {
    _name = name;
}

string SelfDevelopment::getEmail()  {
    return _email;
}

void SelfDevelopment::setEmail(string email) {
    _email = email;
}

string SelfDevelopment::getStartDate()  {
    return _startDate;
}

void SelfDevelopment::setStartDate(string startDate) {
    _startDate = startDate;
}

double SelfDevelopment::getCost()  {
    return _cost;
}

void SelfDevelopment::setCost(double cost) {
    _cost = cost;
}

string  SelfDevelopment::typePersion() {
    return "AwakenPower";
}
string  SelfDevelopment::counreses() {
    return "Awaken your power";
}
double  SelfDevelopment::help() {
    return 17;
}
double  SelfDevelopment::total() {
    return getCost() + help();
}
string  SelfDevelopment::toString() {
    return "Self development";
}