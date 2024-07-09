#pragma once
#include<iostream>
#include<vector>
#include<math.h>
#include<string>
using namespace std;
class Rectangle {
private:
    int _width;
    int _height;
public:
    Rectangle();
    Rectangle(int width, int height);
    string toString();

    int getWidth() { return  _width; };
    int getHeight() { return _height; };

};

class SolidRectangleConverter {
private:
    string character;
public:
    string convert(Rectangle info);
    SolidRectangleConverter() { character = ""; };
    SolidRectangleConverter(string arg) {
        character = arg;
    };
};

class HollowRectangleConverter {
private:
    string character;
public:
    string convert( Rectangle info);
    HollowRectangleConverter() { character = ""; };
    HollowRectangleConverter(string arg) {
        character = arg;
    }
};