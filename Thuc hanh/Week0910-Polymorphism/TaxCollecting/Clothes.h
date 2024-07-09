#pragma once
#include"Object1.h"
#include"ITaxCollecting.h"

class Clothes :public ITaxCollecting
{
private:
    std::string _id;
    double _area;
public:
    // Constructor
    Clothes();
    Clothes(const std::string& id, double area);

    // Setters
    void setId(const std::string& id);
    void setArea(double area);

    double LeaseholdCash() override;
    double OtherCosts() override;
    double Total() override;
    std::string IDRent() override;
    double AreaRent() override;
    inline std::string toString() override;
};

