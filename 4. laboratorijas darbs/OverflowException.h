#pragma once
#include <iostream>
using namespace std;

class OverflowException {
public:
	OverflowException() {
		cout << endl << "Overflow exception created!" << endl;
	}
	OverflowException(const OverflowException&) {
		cout << "Overflow exception copied!" << endl;
	}
	~OverflowException() {
		cout << "Overflow exception finished!" << endl;
	}
};
