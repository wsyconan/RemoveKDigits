#pragma once
#include<iostream>
#include<vector>
#include<fstream>

using namespace std;

class RemoveKDigits {
public:
	RemoveKDigits();
	RemoveKDigits(string, int);
	~RemoveKDigits();
	
private:
	string num;
	string file_name;
	int k;

	void reomve();
};