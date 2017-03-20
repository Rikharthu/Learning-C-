#include <iostream>
#include <cstdio>
#include <string>
#include "Car.h"
#include "CarPark.h"
#include "OverflowException.h"

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

//+ CarPark
const unsigned int CarPark::DEFAULT_MAX_CAR_COUNT = 5;
CarPark::~CarPark() {
	// delete each individual Car (not required in newest C++)
	for (unsigned int i = 0; i<Length; i++)
		delete Cars[i];
	// free Array memory
	delete[] Cars;
}
inline void CarPark::Print() const {
	cout << "Cars: " << Length << "/" << MaxLength << endl;
	for (unsigned int i = 0; i<Length; i++) {
		cout << (i + 1) << ". ";
		cout << Cars[i]->toString();
		cout << "." << endl;
	}
}

inline void CarPark::ParkCar(const Car & car) {
	cout << "Parking reference to a car" << endl;
	if (Length == MaxLength)
		throw OverflowException();
	else {
		// Copy constructor
		Cars[Length++] = new Car(car);
		cout << "Empty spaces: " << MaxLength - Length << endl;
	}
}

inline void CarPark::ParkCar(const Car * car) {
	cout << "Parking pointer to a car" << endl;
	if (Length == MaxLength)
		throw OverflowException();
	else {
		// ?+ Copy constructor ???
		Cars[Length++] = new Car(*car);
		cout << "Empty spaces: " << MaxLength - Length << endl;
	}
}

inline int CarPark::GetMaxPower() const {
	int max = 0;
	for (unsigned int i = 0; i<Length; i++) {
		if (Cars[i]->GetMotorPower() > max) {
			max = Cars[i]->GetMotorPower();
		}
	}
	return max;
}

//++ Main()
void main(void) {
	system("CLS");

	CarPark * park = new CarPark();
	Car * nissan = new Car("FO-3390", 2006, "Japan", 1550);
	Car unixCar = Car();

	try {
		park->ParkCar(nissan);
	}
	catch (OverflowException&) {
		cout << "There's empty places left! Turn Back!" << endl;
	}
	catch (...) {
		// any other exceptions
		cout << "Something bad happened in the car park..." << endl;
	}
	delete(nissan);

	cout << "\n\nDefault maximal length (from CLASS): " <<
		CarPark::GetDefaultMaxCarCount() << "." << endl;
	cout << "Default maximal length (from OBJECT): " <<
		park->GetDefaultMaxCarCount() << "." << endl;
	cout << "Maximal length: " << park->GetMaxLength() << "." << endl;
	cout << "Current length: " << park->GetLength() << "." << endl;
	park->Print();
	cout << endl;
	try {
		park->ParkCar(unixCar);
		park->ParkCar(unixCar);
		// will throw ... exception
		park->ParkCar(nissan);
	}
	catch (OverflowException&) {
		cout << "There's empty places left! Turn Back!" << endl;
	}
	catch (...) {
		// any other exceptions
		cout << "Something bad happened in the car park..." << endl;
	}
	park->Print();
	cout << endl;
	try {
		park->ParkCar(unixCar);
		park->ParkCar(unixCar);
		park->ParkCar(unixCar);
	}
	catch (OverflowException&) {
		cout << "There's empty places left! Turn Back!" << endl;
	}
	catch (...) {
		// any other exceptions
		cout << "Something bad happened in the car park..." << endl;
	}

	park->Print();
	cout << "Max power is " << park->GetMaxPower() << endl;
	delete park;

	getchar();
}
