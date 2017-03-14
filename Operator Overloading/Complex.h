#pragma once
#include <cstdio>
#include <iostream>
#include	<string>
#include <math.h>

using namespace std;

class Complex {
private:
	int real, imaginary;

public:
	int getReal() const{
		return real;
	}
	int getImaginary() const {
		return imaginary;
	}
	Complex(int real=0, int imaginary=0) :real(real), imaginary(imaginary) {}

	Complex operator +(const Complex &rhs) const {
		return Complex(real + rhs.getReal(), imaginary + rhs.getImaginary());
	}

	float abs() const {
		return sqrt(pow(real, 2)+ pow(imaginary, 2));
	}

	operator string() const {
		const static int maxstringsize = 64;
		char s[maxstringsize];
		char o = imaginary < 0 ? '-' : '+';
		snprintf(s, maxstringsize, "%d%c%di", real,o, (int)fabs(imaginary));
		return std::string(s);
	}
};