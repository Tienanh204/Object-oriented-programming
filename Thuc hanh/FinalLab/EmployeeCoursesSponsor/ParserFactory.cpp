#include "ParserFactory.h"
#include"IParsable.h"
#include"AwakenPower.h"
#include"SelfDevelopment.h"
#include"Object.h"
#include"FinancialFreedom.h"
#include"ParerAwakenPower.h"
#include"ParerFinancialFreedom.h"
#include"ParerSelfDevelopment.h"

IParsable* ParserFactory::create(std::string type) {
    static std::map<std::string, IParsable*> _container = {
       { "Self development", new ParerAwakenPower() },
       { "Financial freedom", new ParerSelfDevelopment() },
       { "Awaken your power", new ParerFinancialFreedom() }
    };
    IParsable* parse = _container[type];
    return parse;
}

std::string ParserFactory::toString() {
    return "ParserFactory";
}

