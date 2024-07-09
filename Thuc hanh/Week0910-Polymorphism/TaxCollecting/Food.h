#pragma once
#include"Object1.h"
#include"ITaxCollecting.h"

class Food :public ITaxCollecting
{
private:
    std::string _id;
    double _area;
    double _coldStorage;
public:
    Food();
    Food(const std::string& id, double area, double coldStorage);

    // Setters
    void setId(const std::string& id);
    void setArea(double area);
    void setColdStorage(double coldStorage);

    double LeaseholdCash() override;
    double Total() override;
    std::string IDRent() override;
    double AreaRent() override;
    double OtherCosts() override;
    inline std::string toString() override;
};

