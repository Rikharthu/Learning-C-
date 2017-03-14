#pragma once
#include <string>
#include <iostream>

using namespace std;

class Vehicle {
private:
	string regNum;
	int year;
	string country;

public:
	// default constructor
	Vehicle();
	Vehicle(string, int, string);
	// destructor
	virtual ~Vehicle() {
		cout << "Vehicle #" << regNum << " recycled." << endl;
	}

	// getters and setters
	string getRegNum() const {
		return regNum;
	}

	void setRegNum(string regNum) {
		this->regNum = regNum;
	}

	// Not implemented 
	int getYear() const;
	void setYear(int);
	string getCountry() const;
	void setCountry(string);

	virtual string toString() const{
		return string("\"regNum\":\"" + regNum + "\",\n\"year\":" + to_string(year) + ",\n\"country\":" + country);
	}
};