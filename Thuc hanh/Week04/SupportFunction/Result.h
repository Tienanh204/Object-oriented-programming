#pragma once
#include<iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

template <class T>
class Result {
public:
	bool success;
	T data;
	int errorCode;
	string message;
	Result(bool success, const T& data, int errorCode, const string& message) 
		: success(success), data(data), errorCode(errorCode), message(message) {}
};