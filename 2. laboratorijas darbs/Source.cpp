#include <iostream>
#include <cstdio>
#include <string>
#include "Car.h"
//!+++ 3. Variants.
using namespace std;

// Vehicle implementation
// initializer list
Vehicle::Vehicle() : regNum("UNX-01"), year(1970), country("USA") {
	cout << "Vehicle()" << endl;
}

Vehicle::Vehicle(string regNum, int year, string country) {
	cout << "Vehicle(string, int, string)" << endl;
	this->regNum = regNum;
	this->year = year;
	this->country = country;
}

inline int Vehicle::getYear() const {
	return year;
}

inline void Vehicle::setYear(int year) {
	this->year = year;
}

inline string Vehicle::getCountry()const {
	return country;
}

inline void Vehicle::setCountry(string country) {
	this->country = country;
}

inline int Car::GetMotorPower() const {
	return motor_power;
}

Car::Car(string regNum, int year, string country, int motor_power) :Vehicle(regNum, year, country) {
	cout << "Car(string, int, string, int)" << endl;
	this->motor_power = motor_power;
}

Car::Car() : Vehicle() {
	cout << "Car()" << endl;
	motor_power = 1337;
}


void main(void) {
	system("CLS");

	Vehicle *vehicles[4];
	cout << "[0]" << endl;
	vehicles[0] = new Vehicle();
	cout << "[1]" << endl;
	vehicles[1] = new Vehicle("KB-601", 2008, "Germany");
	cout << "[2]" << endl;
	vehicles[2] = new Car();
	cout << "[3]" << endl;
	vehicles[3] = new Car("GU-83", 2002, "USA", 1550);

	cout << endl;

	for (int i = 0; i < 4; i++) {
		cout << "[" + to_string(i) + "]" << endl << vehicles[i]->toString() << endl << "Destroying..." << endl;
		delete vehicles[i];
		cout << endl;
	}

	getchar();
}
