#pragma once
#include <cstdio>

class Triangle {
private:
	int a, b, c;
public:
	void setSize(int aa, int bb, int cc) {
		a = aa;
		b = bb;
		c = cc;
	}
	float area();
	int perimeter();

	// tas ir pre-increment, jeb ++x (nevis x++)
	Triangle& operator++() {
		// katru malu palielina par 1
		++a;
		++b;
		++c;
		return *this;
	}

	// postifx operacija
	Triangle operator++(int) {
		// int parametrs n ir fiktīvs (tikai lai atšķirtu
		Triangle old = *this; // objekta kopija
		++a; ++b; ++c;
		return *this;
	}

	/*
	Triangle& operator*(int n) {
		a *= n;
		b *= n;
		c *= n;
		// Atgriežama vērtība ir pats objekts
		return *this;
	}
	*/
	// x=x*2 - izpildisies x.operator*(2)
	// x=2*x - nav iespejams, jo formali butu jaizpilda 2.operator*(x)
	// ir jaraksta cita funkcija, bet ar klases metodi to nevar realizet
	// jadeklarē tos ka friend funkcijas, lai tie varēti piekļūt pie a, b un c
	// 2*x
	friend Triangle& operator*(int, const Triangle&);
	// x*2
	friend Triangle& operator*(const Triangle&, int);

	void print() {
		cout << "a=" << a << ", b=" << b << ", c=" << c << endl;
	}
};

// Operaciju x@y var realizet ar ārēju funkciju operator@(x,y)
Triangle& operator*(int n, const Triangle& ct) {
	// work on other object to avoid original editing in cases such as:
	// t2 = t1*x, which will edit BOTH triangles
	Triangle t = ct;
	t.a = t.a*n;
	t.b=t.b*n;
	t.c = t.c*n;
	return t;
}

// P.S. jau realizēts kā Triangle::Triangle& operator*(int n)
Triangle& operator*(const Triangle& ct, int n) {
	return n*ct;
}