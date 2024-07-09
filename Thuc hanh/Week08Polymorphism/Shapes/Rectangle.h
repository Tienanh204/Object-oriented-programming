#pragma once
#include"IShape.h"

class Rectangle : public IShape {
private:
    double _width;
    double _height;
public:
    Rectangle();
    Rectangle(double width, double height);
    void setWidth(double width);
    void setHeight(double height);
    double getWidth();
    double getHeight();
    double area() override;
    double perimeter() override;
    std::string toString() override;
};

