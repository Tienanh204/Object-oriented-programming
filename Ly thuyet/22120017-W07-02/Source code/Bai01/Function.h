#pragma once
#include<iostream>
#include<string>
#include <map>
#include<vector>
#include<math.h>
using namespace std;

class Gate
{
public:
	virtual void input() = 0;
	virtual int getFeatureGate() = 0;
	virtual int getTypeGate() = 0;
};


class BusinessGate :public Gate
{
private:
	float price;
	int quantity;
public:
	BusinessGate();
	~BusinessGate() {};

	void input();
	int getFeatureGate();
	int getTypeGate() {
		return 1;
	}
};

class AcademicGate :public Gate
{
private:
	int intellect;
public:
	AcademicGate();
	~AcademicGate() {};

	void input();
	int getFeatureGate();
	int getTypeGate() {
		return 2;
	}
};

class Power :public Gate
{
private:
	int power;
public:
	Power();
	~Power() {};

	void input();
	int getFeatureGate();
	int getTypeGate() {
		return 3;
	}
};

class Prince
{
private:
	map<int, Gate*> gate;
public:
	Prince() {};
	Gate*getGate(int type){
		return gate[type];
	}
	void registerGate(Gate* g) {
		gate.insert({ g->getTypeGate(), g });
	}
};