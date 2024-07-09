#include "ParerAwakenPower.h"
#include"Utlis.h"
#include"AwakenPower.h"

string ParerAwakenPower::toString() {
    return "Awaken your power";
}
Object* ParerAwakenPower::parse(std::string input) {
    vector<string> token = Utils::String::split(input, ", ");
    vector<string> name = Utils::String::split(token[0], "=");
    vector<string> email = Utils::String::split(token[1], "=");
    vector<string> date = Utils::String::split(token[2], "=");
    vector<string> cost = Utils::String::split(token[3], "=$");

    return new AwakenPower(name[1], email[1], date[1], (double)stoi(cost[1]));
}
