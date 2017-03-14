#include <cstdio>
#include <string>
#include <math.h>

using namespace std;

class Gamma
{
	int m;
	static int ms;
public:
	static void comp(int, char);
};

int Gamma::ms = 0;

void Gamma::comp(int i, char c) {
	// m=i; // Error
	ms = i + c;
	// this->ms = i; // Error
}

class TriangC
{
	int a, b, c, color;
	// statiska konstante
	static const double DEG2RAD;
	static const int max = 10;
public:
	TriangC(int, int, int, int);
	// statiskas funkcijas kas rada jaunus objektus
	static TriangC* make(int, int);
	static TriangC* make(int, int, double, int);
};

const double TriangC::DEG2RAD = 3.141592654 / 180;

TriangC::TriangC(int a, int b, int c, int color) {
	this->a = a;
	this->b = b;
	this->c = c;
	this->color = color;
}

TriangC* TriangC::make(int side, int color) {
	if (side <= 0) return NULL;
	return new TriangC(side, side, side, color);
}

TriangC* TriangC::make(int a, int b, double alpha_deg, int color) {
	if (a <= 0 || b <= 0) {
		return NULL;
	}
	int c = (int)sqrt(a*a + b*b - 2 * a*b*cos(DEG2RAD*alpha_deg));
	return new TriangC(a, b, c, color);
}


int main(int argc, char ** argv) {
	int k = 3;
	Gamma::comp(k, 'A'); // Ok

	Gamma a;
	a.comp(k, 'B'); // Ok
	// comp(13, 'C'); // Error
	Gamma::comp(12, 'D'); // Ok


	TriangC t0(3, 4, 5, 1);
	// t0 = TriangC::make(3,1); // Error

	TriangC*t1;
	t1 = TriangC::make(3, 1);
	delete t1;
	t1 = TriangC::make(3, 4, 90, 1);
	delete t1;
	t1 = TriangC::make(-3, 1); // NULL

	getchar();
	return 0;
}
