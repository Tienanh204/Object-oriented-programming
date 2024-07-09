#pragma once
#include<iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class RandomInteger {
public:
    RandomInteger() {
        srand(static_cast<unsigned int>(time(nullptr)));
    }

    int next() {
        return rand() % 65536;
    }

    int next(int max) {
        return rand() % max;
    }

    int next(int left, int right) {
        return left + rand() % (right - left + 1);
    }
};