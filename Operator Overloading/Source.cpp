// rational.cpp by Bill Weinman <http://bw.org/>
#include <cstdio>
#include <iostream>
#include	<string>
#include "Complex.h"
#include "Vect.h"
#include "Triangle.h"
using namespace std;


class Rational
{
	int _n = 0;
	int _d = 1;

public:
	Rational(int numerator = 0, int denominator = 1) : _n(numerator), _d(denominator) {};
	Rational(const Rational &rhs) : _n(rhs._n), _d(rhs._d) {}; // copy constructor
	~Rational();
	inline int numerator() const { return _n; };
	inline int denominator() const { return _d; };
	Rational &operator=(const Rational &);
	Rational operator+(const Rational &) const;
	Rational operator-(const Rational &) const;
	Rational operator*(const Rational &)const;
	Rational operator/(const Rational &) const;
	// Conversion operator overload
	// Returns an operator itself
	operator std::string() const;
};

Rational &Rational::operator=(const Rational &rhs)
{
	if (this != &rhs)
	{
		_n = rhs.numerator();
		_d = rhs.denominator();
	}
	// in method declaration we return  & Rational
	// => we need to reference pointer to "this"
	// because "this" gives a reference/address of the current object
	return *this;
}

Rational Rational::operator+(const Rational &rhs) const
{
	return Rational((_n * rhs._d) + (_d * rhs._n), _d * rhs._d);
}

Rational Rational::operator-(const Rational &rhs) const
{
	return Rational((_n * rhs._d) - (_d * rhs._n), _d * rhs._d);
}

Rational Rational::operator*(const Rational &rhs) const
{
	return Rational(_n * rhs._n, _d * rhs._d);
}

Rational Rational::operator/(const Rational &rhs) const
{
	return Rational(_n * rhs._d, _d * rhs._n);
}

Rational::~Rational()
{
	cout << "dtor: " << _n << "/" << _d << endl;
	_n = 0;
	_d = 1;
}

Rational::operator std::string() const{
	const static int maxstringsize = 64;
	char s[maxstringsize];
	snprintf(s, maxstringsize, "%d/%d", _n, _d);
	return std::string(s);
}

// Already defined above, nonmember version
//Rational &operator+(const Rational &lhs, const Rational &rhs)
//{
//	return Rational((lhs.numerator() * rhs.numerator) + (lhs.denominator() + rhs.numerator), lhs.denominator * rhs.denominator);
//}

// Nonmember operator overload
// useful for std::cout
std::ostream &operator<<(std::ostream &o, const Rational &r)
{
	return o << r.numerator() << '/' << r.denominator();
}



int main(int argc, char **argv)
{

	Rational a = 7; // 7/1
	cout << "a is: " << a << endl;
	Rational b(5, 3); // 5/3
	cout << "b is: " << b << endl;
	Rational c = b; // copy constructor
	cout << "c is: " << c << endl;
	Rational d; // default constructor
	cout << "d is: " << d << endl;
	d = c; // assignment operator
	cout << "d is: " << d << endl;
	Rational &e = d; // reference
	d = e;           // assignment to self!
	cout << "e is: " << e << endl;

	cout << a << " + " << b << " = " << a + b << endl;
	cout << a << " - " << b << " = " << a - b << endl;
	cout << a << " * " << b << " = " << a * b << endl;
	cout << a << " / " << b << " = " << a / b << endl;

	string s = "Rational as a string: ";
	// Conversion operator overload
	s += b;
	cout << s << endl;

	Complex i1 = { 3 };
	string i1str = i1;
	cout <<"i1: "<< i1str << endl;
	Complex i2 = { 12,-7 };
	cout << "i2: " << string(i2) << endl;

	Complex irez = i1 + i2;
	cout << "i1+i2: " << string(irez) << endl;

	float abs = irez.abs();
	cout << "abs: " << abs << endl;


	//++ Vect Demo
	cout << "\nVect demo:" << endl;
	Vect v1;
	Vect v2(7);

	int i;
	for (i = 0; i < v1.getsize(); ++i) v1[i] = i + 100; // use overloaded [], i.e. v1.operator[](i) = i + 100;
	v1.print(v1.getsize());

	for (i = 0; i < v2.getsize(); ++i) v2[i] = i + 200; // use overloaded [], i.e. v2.operator[](i) = i + 200;
	v2.print();

	getchar();

	int m[] = { 11, 12, 13, 14, 15, 16, 17, 18, 19 };
	Vect v3(m, 5);
	v3.print();

	v3 = v1;	// use overloaded assignment =, i.e. v3.operator=(v1);
	v3.print();

	getchar();

	for (i = 0; i < 5; ++i) v3[i] = i;  	// use overloaded []

	v3.print();

	++v3;		// use overloaded ++, i.e. v3.operator++();
	v3.print();

	getchar();

	v3 = 1000 + v3; // use overloaded +, i.e. operator+(1000, v3) and overloeded =
	v3.print();
	v3 = v3 + 2000; // use overloaded +, i.e. v3.operator+(2000) and overloaded =
	v3.print();

	cout << "\n\nTriangle Demo:" << endl;
	Triangle t1;
	t1.setSize(3, 4, 5);
	t1.print();

	Triangle t2;	
	t2 = t1 * 2;
	t1.print();
	t2.print();

	t1++;
	++t2;
	t1.print();
	t2.print();

	getchar();
	return 0;
}
