#include <iostream>
#include <cstdio>

using namespace std;

int main() {

	//+ Pointers to Pointers
	puts("\n\n-- Pointers to Pointers --\n");
	int  var;
	int  *ptr;
	int  **pptr;

	var = 3000;

	// take the address of var
	ptr = &var;

	// take the address of ptr using address of operator &
	pptr = &ptr;

	// take the value using pptr
	cout << "Value of var :" << var << endl;
	cout << "Value available at *ptr :" << *ptr << endl;
	cout << "Value available at **pptr :" << **pptr << endl;

	getchar();

	return 0;
}