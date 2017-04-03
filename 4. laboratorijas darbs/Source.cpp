#include <iostream>
#include <cstdio>
#include <string>
#include "Car.h"
#include "CarPark.h"
#include "OverflowException.h"

//!+++ 3. Variants.
using namespace std;

// initializer list
template <typename T>
Vehicle<T>::Vehicle() : regNum("UNX-01"), year(1970), country("USA") {
	cout << "Vehicle()" << endl;
}

template <typename T>
Vehicle<T>::Vehicle(string regNum, T year, string country) {
	cout << "Vehicle(string, int, string)" << endl;
	this->regNum = regNum;
	this->year = year;
	this->country = country;
}

template <typename T>
T Vehicle<T>::getYear() const {
	return year;
}

template <typename T>
void Vehicle<T>::setYear(T year) {
	this->year = year;
}

template <typename T>
string Vehicle<T>::getCountry()const {
	return country;
}

template <typename T>
void Vehicle<T>::setCountry(string country) {
	this->country = country;
}

template <typename T>
int Car<T>::GetMotorPower() const {
	return motor_power;
}

template <typename T>
Car<T>::Car(string regNum, T year, string country, int motor_power) :Vehicle(regNum, year, country) {
	cout << "Car(string, int, string, int)" << endl;
	this->motor_power = motor_power;
}

template <typename T>
Car<T>::Car() : Vehicle() {
	cout << "Car()" << endl;
	motor_power = 1337;
}

//+ CarPark
template <typename T>
const unsigned int CarPark<T>::DEFAULT_MAX_CAR_COUNT = 5;
template <typename T>
CarPark<T>::~CarPark() {
	// delete each individual Car (not required in newest C++)
	for (unsigned int i = 0; i<Length; i++)
		delete Cars[i];
	// free Array memory
	delete[] Cars;
}

template <typename T>
void CarPark<T>::Print() const {
	cout << "Cars: " << Length << "/" << MaxLength << endl;
	for (unsigned int i = 0; i<Length; i++) {
		cout << (i + 1) << ". ";
		cout << Cars[i]->toString();
		cout << "." << endl;
	}
}

template <typename T>
void CarPark<T>::ParkCar(const Car<T> & car) {
	cout << "Parking reference to a car" << endl;
	if (Length == MaxLength)
		throw OverflowException();
	else {
		// Copy constructor
		Cars[Length++] = new Car<T>(car);
		cout << "Empty spaces: " << MaxLength - Length << endl;
	}
}

template <typename T>
void CarPark<T>::ParkCar(const Car<T> * car) {
	cout << "Parking pointer to a car" << endl;
	if (Length == MaxLength)
		throw OverflowException();
	else {
		// ?+ Copy constructor ???
		Cars[Length++] = new Car<T>(*car);
		cout << "Empty spaces: " << MaxLength - Length << endl;
	}
}

template <typename T>
int CarPark<T>::GetMaxPower() const {
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
	
	CarPark<unsigned int> * uIntCarPark = new CarPark<unsigned int>();
	CarPark<unsigned long> * uLongCarPark = new CarPark<unsigned long>();

	Car<unsigned int> * nissan = new Car<unsigned int>("FO-3390", 2006, "Japan", 1550);
	Car<unsigned int> unixCar = Car<unsigned int>();
	Car<unsigned long> * chrysler = new Car<unsigned long>("GU-83", 2003, "USA", 1900);

	uIntCarPark->ParkCar(nissan);
	uIntCarPark->ParkCar(unixCar);
	// error
	//uIntCarPark->ParkCar(chrysler);
	uLongCarPark->ParkCar(chrysler);

	uIntCarPark->Print();
	uLongCarPark->Print();

	/*
	CarPark<long> * park = new CarPark<long>();
	Car<unsigned long> * nissan = new Car<unsigned long>("FO-3390", 2006, "Japan", 1550);
	Car<unsigned short> unixCar = Car<unsigned short>();

	std::cout << "Nissan arrived" << endl;
	try {
		park->ParkCar(nissan);
	}
	catch (OverflowException&) {
		std::cout << "There's empty places left! Turn Back!" << endl;
	}
	catch (...) {
		// any other exceptions
		std::cout << "Something bad happened in the car park..." << endl;
	}
	delete(nissan);
	
	std::cout << "\n\nDefault maximal length (from CLASS): " <<
		CarPark<long>::GetDefaultMaxCarCount() << "." << endl;
	std::cout << "Default maximal length (from OBJECT): " <<
		park->GetDefaultMaxCarCount() << "." << endl;
	std::cout << "Maximal length: " << park->GetMaxLength() << "." << endl;
	std::cout << "Current length: " << park->GetLength() << "." << endl;
	park->Print();
	std::cout << endl;
	
	std::cout << "2 unix cars and 1 destroyed nissan drove by" << endl;
	try {
		park->ParkCar(unixCar);
		park->ParkCar(unixCar);
		// will throw ... exception
		park->ParkCar(nissan);
	}
	catch (OverflowException&) {
		std::cout << "There's empty places left! Turn Back!" << endl;
	}
	catch (...) {
		// any other exceptions
		std::cout << "Something bad happened in the car park..." << endl;
	}
	park->Print();
	std::cout << endl;

	std::cout << "2 more cars arrived." << endl;
	try {
		park->ParkCar(unixCar);
		park->ParkCar(unixCar);
		park->ParkCar(unixCar);
	}
	catch (OverflowException&) {
		std::cout << "There's empty places left! Turn Back!" << endl;
	}
	catch (...) {
		// any other exceptions
		std::cout << "Something bad happened in the car park..." << endl;
	}

	park->Print();
	std::cout << "Max power is " << park->GetMaxPower() << endl;
	std::cout << "Car park is closing..." << endl;
	delete park;
	*/
	getchar();
}
