#include"Flyweight.h"

// TreeType (Flyweight)
TreeType::TreeType(const std::string& color, const std::string& texture)
    : color(color), texture(texture) {}

void TreeType::draw(int x, int y) const {
    std::cout << "Drawing tree at (" << x << ", " << y << ") with color "
        << color << " and texture " << texture << std::endl;
}
std::string TreeType::getColor() {
    return color;
}
std::string TreeType::getTexture() {
    return texture;
}

// Tree (Concrete Flyweight User)
Tree::Tree(int x, int y, std::shared_ptr<TreeType> type)
    : x(x), y(y), type(type) {}

void Tree::draw() const {
    type->draw(x, y);
}

// TreeTypeFactory
std::shared_ptr<TreeType> TreeTypeFactory::getTreeType(const std::string& color, const std::string& texture) {
    for (auto& type : cache) {
        if (type->getColor() == color && type->getTexture() == texture) {
            return type;
        }
    }
    auto newType = std::make_shared<TreeType>(color, texture);
    cache.push_back(newType);
    return newType;
}

// VehicleType (Flyweight)
VehicleType::VehicleType(const std::string& brand, const std::string& texture)
    : brand(brand), texture(texture) {}

void VehicleType::draw(int x, int y) const {
    std::cout << "Drawing vehicle at (" << x << ", " << y << ") with brand "
        << brand << " and texture " << texture << std::endl;
}
std::string VehicleType::getBrand() {
    return brand;
}
std::string VehicleType::getTexture() {
    return texture;
}

// Vehicle (Concrete Flyweight User)
Vehicle::Vehicle(int x, int y, std::shared_ptr<VehicleType> type)
    : x(x), y(y), type(type) {}

void Vehicle::draw() const {
    type->draw(x, y);
}


// VehicleTypeFactory
std::shared_ptr<VehicleType> VehicleTypeFactory::getVehicleType(const std::string& brand, const std::string& texture) {
    for (auto& type : cache) {
        if (type->getBrand() == brand && type->getTexture() == texture) {
            return type;
        }
    }
    auto newType = std::make_shared<VehicleType>(brand, texture);
    cache.push_back(newType);
    return newType;
}


// BuildingType (Flyweight)
BuildingType::BuildingType(const std::string& name, const std::string& texture)
    : name(name), texture(texture) {}

void BuildingType::draw(int x, int y) const {
    std::cout << "Drawing building at (" << x << ", " << y << ") with name "
        << name << " and texture " << texture << std::endl;
}
std::string BuildingType::getName() {
    return name;
}
std::string BuildingType::getTexture() {
    return texture;
}


// Building (Concrete Flyweight User)
Building::Building(int x, int y, std::shared_ptr<BuildingType> type)
    : x(x), y(y), type(type) {}

void Building::draw() const {
    type->draw(x, y);
}


// BuildingTypeFactory
std::shared_ptr<BuildingType> BuildingTypeFactory::getBuildingType(const std::string& name, const std::string& texture) {
    for (auto& type : cache) {
        if (type->getName() == name && type->getTexture() == texture) {
            return type;
        }
    }
    auto newType = std::make_shared<BuildingType>(name, texture);
    cache.push_back(newType);
    return newType;
}


// Game class that holds all objects
void Game::addObject(const std::shared_ptr<Object>& obj) {
    objects.push_back(obj);
}
void Game::draw() const {
    for (const auto& obj : objects) {
        obj->draw();
    }
}