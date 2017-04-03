#include <cstdio>
#include <iostream>
#include	<string>

using namespace std;

float myFunc(float a, float b) {
	if (b == 0) {
		errno++;
		return -1;
	}
	return a / b;
}

void broken() {
	cout << "This is a broken function" << endl;
	throw exception();
}

// Create custom exception that extends standart exception
class MyException : public exception {
public:
	// C++ standart excepiton has a virtual what() method, which describes the exception
	virtual const char* what() const throw()
	{
		return "My exception happened";
	}

};

int main(int argc, char **argv)
{
	//!++ errno approach:
	// идея состоит в том, что есть глобальная переменная errno, 
	// которую можно увеличивать и обновлять.
	// Некоторые библиотеки увеличивают её, если происходит ошибка.
	// Поэтому перед каждым использованием какой-либо функции стоит её обнулять
	// и проверять на >0, т.е. произошла ли ошибка
	// reset error count before each library call
	errno = 0;
	printf("Error count before function call: %d\n", errno);
	float a = 13, b = 0;
	float res = myFunc(a, b);

	if (errno > 0) {
		printf("errno=%d, something wrong has happened during library function call...\n",errno);
	}
	else {
		printf("%f / %f = %f", a, b, res);
	}
	printf("Error count after function call: %d\n", errno);

	//!++ Handling Exceptions:
	try {
		broken();
	}
	catch (exception & e) {
		cout << "This can't be good: " << e.what() << endl;
	}
	catch (int param) {
		cout << "int exception: " << param << endl;
	}
	catch (MyException & e) {
		cout << "My Exception: " << e.what() << endl;
	}
	catch (...) {
		cout << "Any other exception" << endl;
	}

	getchar();
	return 0;
}
