#pragma once
#include"Object.h"
class AwakenPower: public Object
{
private:
	string _name;
	string _email;
	string _startDate;
	double _cost;
public:
    AwakenPower();
    AwakenPower(string name, string email, string startDate, double cost);

    // Getter and Setter methods
     string getName() ;

     void setName(string name);

     string getEmail() ;

     void setEmail(string email);
     string getStartDate() ;

     void setStartDate(string startDate);
     double getCost() ;

     void setCost(double cost);

     string typePersion();
     string counreses();
     double help();
     double total();
     string toString() override;
};

