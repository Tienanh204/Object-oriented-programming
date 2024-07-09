#pragma once
#include"Object.h"
#include"IParsable.h"
#include"IShape.h"
#include"ParserFactory.h"
#include"Utils.h"

int main() {
    std::vector<std::string> lines = {
        "Square: a=12",
        "Circle: r=12",
        "Square: a=7",
        "Rectangle: w=3, h=4",
        "Rectangle: w=6, h=8",
        "Circle: r=5",
        "Square: a=8"
    };

    ParserFactory factory;
    std::vector<IShape*> shapes;

    for (auto& line : lines) {
        // Example: line = "Square: a=12"
        std::vector<std::string> tokens = Utils::String::split(line, ": ");
        IParsable* parser = factory.create(tokens[0]); // "Square"=> SquareParser
        IShape* shape = dynamic_cast<IShape*> (parser->parse(tokens[1])); // "a=12" => Square(_a = 12)
        shapes.push_back(shape);
    }

    for (auto& shape : shapes) { // Polymorphism
        std::cout << shape->toString() << ": area="
            << shape->area() << ", perimeter="
            << shape->perimeter() << std::endl;
    }
}