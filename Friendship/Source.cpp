#include <cstdio>
#include <string>
#include <math.h>

using namespace std;

/* Klases draugs (friend) ir funkcija vai klase, kurai ir
tiesibas pieklut klases private un protected locekliem,
kaut ari ta nav sis klases loceklis
Par klases draugu var deklarēt:
 - ārēju (globālu) funkciju
 - citas klases funkciju
 - citu klasi (visas sis klases funkcijas)
 Draudziba nav tranzitiva un to nemanto */

class X {
private:
	int g;
public:
	void funX();
};

//++ Example 1 - Friend function in another class
class Y {
private:
	int n;
	float p;
	// Declare a friend function (funX in X class)
	friend void X::funX();
};

void X::funX() {
	// funX is declared class's Y friend
	// => it can access it's private and protected fields
	Y y;
	y.n = 2;
}

//++ Example 2 - global Friend function
class MyType {
private:
	int length;
public:
	void setLength(int);
	// declare global friend function
	//! klases draugi nav klases locekli!
	friend void functEx(MyType*, int);
};

//! Ir klases loceklis
void MyType::setLength(int n) {
	this->length = n;
}

//! Nav klases loceklis
// globala funkcija kas nepieder nevienai klasei!
void functEx(MyType* p, int k) {
	p->length = k;
}


//++ Example 3 - Friend Class
class Beta {
private:
	int b;
	float calcB();
public:
	void clearB();
	// Funkcijas calcB() un clearB()
	// var lietots klases Alpha loceklus a un functA()
};

class Alpha {
private:
	int a;
	void functA();
	// declare friend class
	friend class Beta;
};


int main(int argc, char ** argv) {
	Alpha a;
	getchar();
	return 0;
}
