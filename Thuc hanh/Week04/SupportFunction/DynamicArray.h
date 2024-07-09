#pragma once
#include<iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

template <class T>
class DynamicArray {
private:
    T* array;
    int capacity;
    int size;

public:
    DynamicArray() : capacity(10), size(0) {
        array = new T[capacity];
    }

    ~DynamicArray() {
        delete[] array;
    }

    void add(const T& item) {
        if (size == capacity) {
            resize();
        }
        array[size++] = item;
    }

    T& operator[](int index) {
        return array[index];
    }

    int getSize() const {
        return size;
    }

private:
    void resize() {
        capacity *= 2;
        T* newArray = new T[capacity];
        for (int i = 0; i < size; ++i) {
            newArray[i] = array[i];
        }
        delete[] array;
        array = newArray;
    }
};
