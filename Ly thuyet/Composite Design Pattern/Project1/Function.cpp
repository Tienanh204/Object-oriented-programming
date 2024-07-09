#include"Function.h"

Order::Order(string name, int quantity, int price)
{
	_name = name;
	_quantity = quantity;
	_price = price;
}

int Order::totalCost()
{
	return _quantity * _price;
}

SingleOrder::SingleOrder(string name, int quantity, int price)
	:Order(name, quantity, price) {};

int SingleOrder::totalCost()
{
	return _quantity * _price;
}

CompositeOder::CompositeOder(string name, int quantity, int price)
	:Order(name, quantity, price) {};

void CompositeOder::addOrder(Order* order)
{
	components.push_back(order);
}

void CompositeOder::removeOrder(Order* order)
{
	auto reOrder = find(components.begin(), components.end(), order);
	if (reOrder != components.end())
	{
		components.erase(reOrder);
	}
}

int CompositeOder::totalCost()
{
	int total = 0;
	for (auto order : components)
	{
		total += order->totalCost();//Goi toi SingleOrder
	}
	return total;
}