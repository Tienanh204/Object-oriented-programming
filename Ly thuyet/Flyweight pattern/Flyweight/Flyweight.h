#include <iostream>
#include <vector>
#include <string>
#include <memory>

// Interface Object
class Object {
public:
    virtual void draw() const = 0;
    virtual ~Object() = default;
};

// TreeType (Flyweight)
class TreeType {
private:
    std::string color;
    std::string texture;
public:
    TreeType(const std::string& color, const std::string& texture);

    void draw(int x, int y) const;
    std::string getColor();
    std::string getTexture();
};

// Tree (Concrete Flyweight User)
class Tree : public Object {
private:
    int x, y;
    std::shared_ptr<TreeType> type;// <=> TreeType* type
public:
    Tree(int x, int y, std::shared_ptr<TreeType> type);

    void draw() const override;
};

// TreeTypeFactory
class TreeTypeFactory {
private:
    std::vector<std::shared_ptr<TreeType>> cache;
public:
    std::shared_ptr<TreeType> getTreeType(const std::string& color, const std::string& texture);
};

// VehicleType (Flyweight)
class VehicleType {
private:
    std::string brand;
    std::string texture;
public:
    VehicleType(const std::string& brand, const std::string& texture);

    void draw(int x, int y) const;
    std::string getBrand();
    std::string getTexture();
};

// Vehicle (Concrete Flyweight User)
class Vehicle : public Object {
private:
    int x, y;
    std::shared_ptr<VehicleType> type;
public:
    Vehicle(int x, int y, std::shared_ptr<VehicleType> type);

    void draw() const override;
};

// VehicleTypeFactory
class VehicleTypeFactory {
private:
    std::vector<std::shared_ptr<VehicleType>> cache;
public:
    std::shared_ptr<VehicleType> getVehicleType(const std::string& brand, const std::string& texture);
};


// BuildingType (Flyweight)
class BuildingType {
private:
    std::string name;
    std::string texture;
public:
    BuildingType(const std::string& name, const std::string& texture);

    void draw(int x, int y) const;
    std::string getName();
    std::string getTexture();
};

// Building (Concrete Flyweight User)
class Building : public Object {
private:
    int x, y;
    std::shared_ptr<BuildingType> type;
public:
    Building(int x, int y, std::shared_ptr<BuildingType> type);
    void draw() const override;
};

// BuildingTypeFactory
class BuildingTypeFactory {
private:
    std::vector<std::shared_ptr<BuildingType>> cache;
public:
    std::shared_ptr<BuildingType> getBuildingType(const std::string& name, const std::string& texture);
};


// Game class that holds all objects
class Game {
private:
    std::vector<std::shared_ptr<Object>> objects;
public:
    void addObject(const std::shared_ptr<Object>& obj);
    void draw() const;
};
