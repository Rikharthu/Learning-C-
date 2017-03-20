#pragma once
#include "Car.h"

using namespace std;


class CarPark {
private:
	typedef Car * CarPointer;
	CarPointer *Cars;
	static const unsigned int DEFAULT_MAX_CAR_COUNT;
	unsigned int MaxLength;
	unsigned int Length;
	//unsigned int LineColor;

public:
	// Constructors
	CarPark() : MaxLength(DEFAULT_MAX_CAR_COUNT), Length(0) {
		Cars = new CarPointer[MaxLength];
	}
	CarPark(unsigned int MaxLength) :MaxLength(MaxLength), Length(0) {
		Cars = new CarPointer[MaxLength];
	}
	~CarPark();

	int GetMaxPower() const;

	static unsigned int GetDefaultMaxCarCount() {
		return DEFAULT_MAX_CAR_COUNT;
	}

	void ParkCar(const Car& car);
	void ParkCar(const Car * car);
	int GetMaxLength() const {
		return MaxLength;
	}
	int GetLength() const {
		return Length;
	}

	void Print()const;
};