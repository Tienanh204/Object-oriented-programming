#pragma once
#include"Object.h"

class IShape : public Object {
public:
    virtual double area() = 0;
    virtual double perimeter() = 0;
};
