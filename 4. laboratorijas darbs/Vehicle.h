#pragma once
#include <string>
#include <iostream>

using namespace std;

template <typename T>
class Vehicle {
private:
	string regNum;
	T year;
	string country;

public:
	// default constructor
	Vehicle();
	Vehicle(string, T, string);
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
	T getYear() const;
	void setYear(T);
	string getCountry() const;
	void setCountry(string);

	virtual string toString() const{
		return string("\"regNum\":\"" + regNum + "\",\n\"year\":" + to_string(year) + ",\n\"country\":" + country);
	}
};