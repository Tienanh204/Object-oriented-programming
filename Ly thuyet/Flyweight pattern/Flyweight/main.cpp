#include"Flyweight.h"

int main() {
    TreeTypeFactory treeFactory;
    VehicleTypeFactory vehicleFactory;
    BuildingTypeFactory buildingFactory;

    Game game;

    auto treeType1 = treeFactory.getTreeType("green", "oak");
    auto treeType2 = treeFactory.getTreeType("red", "maple");

    game.addObject(std::make_shared<Tree>(10, 20, treeType1));
    game.addObject(std::make_shared<Tree>(30, 40, treeType2));

    auto vehicleType1 = vehicleFactory.getVehicleType("Toyota", "metallic");
    auto vehicleType2 = vehicleFactory.getVehicleType("Honda", "plastic");

    game.addObject(std::make_shared<Vehicle>(50, 60, vehicleType1));
    game.addObject(std::make_shared<Vehicle>(70, 80, vehicleType2));

    auto buildingType1 = buildingFactory.getBuildingType("House", "brick");
    auto buildingType2 = buildingFactory.getBuildingType("Skyscraper", "glass");

    game.addObject(std::make_shared<Building>(90, 100, buildingType1));
    game.addObject(std::make_shared<Building>(110, 120, buildingType2));

    game.draw();

    return 0;
}
