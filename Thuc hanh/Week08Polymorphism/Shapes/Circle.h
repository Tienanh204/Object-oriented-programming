#pragma once
#include"IShape.h"

class Circle : public IShape {
private:
    double _radius;
public:
    Circle();
    Circle(double radius);
    void setRadius(double radius);
    double getRadius();
    double area() override;
    double perimeter() override;
    std::string toString() override;
};

