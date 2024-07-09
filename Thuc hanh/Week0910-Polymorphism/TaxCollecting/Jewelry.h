#pragma once
#include"Object1.h"
#include"ITaxCollecting.h"

class Jewelry :public ITaxCollecting
{
private:
    std::string _id;
    double _area;
    double _securityFee;
public:
    Jewelry();
    Jewelry(const std::string& id, double area, double fee);

    // Setters
    void setId(const std::string& id);
    void setArea(double area);
    void setSecurityFee(double fee);

    double LeaseholdCash() override;
    double Total() override;
    std::string IDRent() override;
    double AreaRent() override;
    double OtherCosts() override;
    inline std::string toString() override;
};

