#pragma once
#include"..\SupportFunction\RandomInteger.h"
#include"..\SupportFunction\DynamicArray.h"
#include<iostream>
#include<string>
#include<math.h>
using namespace std;

class IntergersInput
{
private:
	int n;
public:
	DynamicArray<int> Arr;
	RandomInteger rand;
	IntergersInput();
	void randInterger();
	void inputArr();
	void printPrime();
	bool Prime(int n);
};