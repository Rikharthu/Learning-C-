// rational.cpp by Bill Weinman <http://bw.org/>
#include <cstdio>
#include <iostream>
#include	<string>

// define min as macro function
#define min_macro(X, Y) ((X) < (Y) ? (X) : (Y))

using namespace std;

// use template approach
template <class T> // vai template <typename T>
T min(T x, T y) {
	return x < y ? x : y;
}


int main(int argc, char **argv)
{
	cout << min_macro(3, 10) << endl;
	cout << min(3, 10) << endl;
	getchar();
	return 0;
}
