#pragma once
#include<iostream>
#include<math.h>
#include<vector>
#include<string>
using namespace std;

// Component: Order
class Order
{
protected:
	string _name;
	int _quantity;
	int _price;
public:
	Order(string name, int quantity, int price);
	virtual int totalCost();
};

// Leaf: SingleOrder
class SingleOrder: public Order
{
public:
	SingleOrder(string name, int quantity, int price);
	int totalCost();
};

// Composite: CompositeOder
class CompositeOder : public Order
{
private:
	vector<Order*> components;
public:
	CompositeOder(string name, int quantity, int price);
	void addOrder(Order* order);
	void removeOrder(Order* order);
	int totalCost();
};