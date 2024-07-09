#include "FinancialFreedom.h"

FinancialFreedom::FinancialFreedom() {};
FinancialFreedom::FinancialFreedom(string name, string email, string startDate, double cost) : _name(name), _email(email), _startDate(startDate), _cost(cost) {}

// Getter and Setter methods
string FinancialFreedom::getName()  {
    return _name;
}

void FinancialFreedom::setName(string name) {
    _name = name;
}

string FinancialFreedom::getEmail()  {
    return _email;
}

void FinancialFreedom::setEmail(string email) {
    _email = email;
}

string FinancialFreedom::getStartDate()  {
    return _startDate;
}

void FinancialFreedom::setStartDate(string startDate) {
    _startDate = startDate;
}

double FinancialFreedom::getCost()  {
    return _cost;
}

void FinancialFreedom::setCost(double cost) {
    _cost = cost;
}

string  FinancialFreedom::typePersion() {
    return "AwakenPower";
}
string  FinancialFreedom::counreses() {
    return "Awaken your power";
}
double  FinancialFreedom::help() {
    return 17;
}
double  FinancialFreedom::total() {
    return getCost() + help();
}
string  FinancialFreedom::toString() {
    return "Financial freedom";
}