#pragma once
#include "Vehicle.h"


using namespace std;


class Car : public Vehicle {
private:
	int motor_power;
public: 
	Car();
	Car(string, int, string, int);
	virtual ~Car() {
		cout << "Car #" << getRegNum() << " recycled." << endl;
	}

	int GetMotorPower() const;

	virtual string toString() const {
		return string(Vehicle::toString() + ",\n\"motor power\":\"" + to_string(motor_power) + "\"");
	}
};

