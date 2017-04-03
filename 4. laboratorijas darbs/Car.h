#pragma once
#include "Vehicle.h"


using namespace std;

template <typename T>
class Car : public Vehicle<T> {
private:
	int motor_power;
public: 
	Car();
	Car(string, T, string, int);
	virtual ~Car() {
		cout << "Car #" << getRegNum() << " recycled." << endl;
	}

	int GetMotorPower() const;

	virtual string toString() const {
		return string(Vehicle::toString() + ",\n\"motor power\":\"" + to_string(motor_power) + "\"");
	}
};

