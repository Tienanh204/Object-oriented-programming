#include "ParserFactory.h"

void ParserFactory::registerWith(IParsable* parser) {
	_container.insert({ parser->parsedObjectName(), parser });
}
IParsable* ParserFactory::create(std::string type) {
	return _container[type];
}
std::string ParserFactory::toString() {
	return "ParserFactory";
}