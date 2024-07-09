#pragma once
#include"IParsable.h"
#include"ParserFactory.h"
#include"RectangleParser.h"
#include"CircleParser.h"
#include"SquareParser.h"

ParserFactory::ParserFactory() {};

std::string ParserFactory::toString()  {
    return "ParserFactory";
}

IParsable* ParserFactory::create(std::string type) {
    IParsable* parser = NULL;

    if ("Rectangle" == type) {
        parser = new RectangleParser();
    }
    else if ("Square" == type) {
        parser = new SquareParser();
    }
    else if ("Circle" == type) {
        parser = new CircleParser();
    }
    return parser;
}