// rational.cpp by Bill Weinman <http://bw.org/>
#include <cstdio>
#include <iostream>
#include	<string>

// define min as macro function
#define min_macro(X, Y) ((X) < (Y) ? (X) : (Y))

using namespace std;

// use template approach
// declare a template
template <class T> // vai template <typename T>
T min(T x, T y) {
	cout << "Called min for type " << typeid(T).name() << ", args: " << x << " and " << y << endl;
	return x < y ? x : y;
}

template <typename T> T max(T a, T b) {
	cout << "Called max for type " << typeid(T).name() << ", args: " << a << " and " << b << endl;
	return a > b ? a : b;
}

//++ Class Template
template <typename ElemType>
class Stack {
	ElemType* stp;
	int max_size;
	int top;

public:
	Stack(int max_size = 10);
	~Stack() {
		delete[] stp;
	}
	Stack(const Stack<ElemType>&);
	Stack<ElemType>& operator=(const Stack<ElemType> &);

	void push(const ElemType newElem);
	ElemType pop(void);
};

template <typename ElemType>
Stack<ElemType>::Stack(int size) {
	top = -1;
	max_size = size;
	stp = new ElemType[max_size];
}

class Vehicle {
	long reg_num;
	int type;
public:
	Vehicle() {
		reg_num = 0;
		type = 0;
	}
	Vehicle(long r_n, int t) {
		reg_num = r_n;
		type = t;
	}
};

// papildus parametriem-tipiem, var noradit ari parametrus-konstantes
// noradot tipe un nosaukumu (n nav tips, veidojot klases objektu
// sa parametra vieta jaraksta konstants lielums 1, 2, 3 ...)
template <class T, int n>
// iespejams ari noradit noklusets vertibas:
//template <class T=int, int n=5>
class Vector2
{
	T data[n];
public:
	T& operator[](int i) {
		return data[i];
	}
};

// Vieglakai koda uztverei sablonu eksemplariem biezi define pseidonimus:
typedef Vector2<int, 13> CursedVector;
CursedVector cv1;
CursedVector cv2;

//++ Mantošans mehanizms:
template <class T>
class CoordPoint {
protected: T X, Y;
public:
	CoordPoint();
	CoordPoint(T, T);
	T GetX() const {
		return X;
	}
	T GetY() const {
		return Y;
	}
	void SetX(T);
	void SetY(T);
};

template <class T>
CoordPoint<T>::CoordPoint() {
	// iespejamas problemas
	X = 0;
	Y = 0;
}

template <class T>
CoordPoint<T>::CoordPoint(T PX, T PY) {
	X = PX;
	Y = PY;
}

template <class T>
void CoordPoint<T>::SetX(T PX) {
	this->X = PX;
}

template <class CT>
class DisplayPoint:CoordPoint<CT> {
	char* color;
public:
	DisplayPoint() :CoordPoint<CT>() {
		color = "white";
	}
	DisplayPoint(CT, CT, char*);
	// ...
};

template <class CT>
DisplayPoint<CT>::DisplayPoint(CT PX, CT PY, char* c) :CoordPoint<CT>(PX, PY)
{
	this->color = c;
}

template<typename lhsT, typename rhsT>
auto tf(lhsT& lhs, rhsT&rhs)->decltype(lhs + rhs) {
	return lhs + rhs;
}


int main(int argc, char **argv)
{
	cout << min_macro(3, 10) << endl;
	cout << min(3, 10) << endl;
	// use argument specified <TYPE>s
	cout << min<long>(3, 10) << endl;
	cout << min<char>(3, 10) << endl;
	cout << min<float>(3, 10) << endl;
	cout << min(3.14, (double)9) << endl;;
	cout << min(0b00010000, 0b00000101) << endl;
	cout << min("abc", "efg") << endl;
	// result for string and char* are different due to implementation
	cout << min<string>("abc", "efg") << endl;
	cout << min('a', 'z') << endl;
	cout << max('a', 'z') << endl;


	Vector2<int, 5> x;
	for (int i = 0; i < 5; ++i) {
		x[i] = i;
	}
	Vector2<int, 10> y;
	y[3] = x[4];
	// ...

	/*
	Stack<int> ist(12); // Seks, kurā var glabāt līdz 12 int tipe objektiem
	Stack<Vehicle> vst(20); // Steks, kurā var glabāt līdz 20 Vehicle tipa objektiem

	ist.push(100);
	ist.push(200);

	Vehicle v1(111, 1);
	Vehicle v2(222, 2);
	vst.push(v1);
	vst.push(v2);

	Vehicle v3 = vst.pop(); // v3.reg_num == 222; v3.type ==2
	*/

	auto autoX = string("This is a string class string");
	decltype(autoX) declY;
	cout << typeid(autoX).name() << endl;
	cout << typeid(declY).name() << endl;

	string strobj("this is a string class string");
	const char * cstr = "this is a c-string";
	auto z = tf(cstr, strobj);
	cout << typeid(z).name() << endl;

	getchar();
	return 0;
}
