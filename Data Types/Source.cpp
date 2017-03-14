#include <cstdio>
#include <cstdint>
#include <iostream>
using namespace std;

int func() {
	static int x = 7;
	return ++x;
}

// pass by reference
int & refInc(int & x) {
	++x;
	return x;
}

// pass by reference, but read-only
const int & refIncConst(const int & x) {
	static int y = x;
	++y;
	return y;
}

int main(int argc, char ** argv)
{
	printf("sizeof char is %ld bits\n", sizeof(char)*8);
	printf("sizeof short int is %ld bits\n", sizeof(short int) * 8);
	printf("sizeof int is %ld bits\n", sizeof(int) * 8);
	printf("sizeof long int is %ld bits\n", sizeof(long int) * 8);
	printf("sizeof long long int is %ld bits\n\n", sizeof(long long int) * 8);

	// cstdint
	printf("sizeof int8_t is %ld bits\n", sizeof(int8_t) * 8);
	printf("sizeof int16_t is %ld bits\n", sizeof(int16_t) * 8);
	printf("sizeof int32_t is %ld bits\n", sizeof(int32_t) * 8);
	printf("sizeof int64_t is %ld bits\n", sizeof(int64_t) * 8);

	// Literal values
	long int x = 42; // decimal int
	printf("x is %ld\n", x);
	x = 42L; // long int
	printf("x is %ld\n", x);
	x = 42U; // unsigned
	printf("x is %ld\n", x);
	x = 052; // octal (because leading zero)
	printf("x is %ld\n", x);
	x = 0b00101010; // binary
	printf("x is %ld\n", x);
	x = 0x2a; // hexadecimal
	printf("x is %ld\n", x);

	//++ FLOATING POINT
	puts("\n\nFloating-point types\n");

	float f = 5e2;
	double df;
	long double ldf;

	printf("float if is %f\n", f);

	printf("size of float f is %ld\n", sizeof(f));
	printf("size of double float f is %ld\n", sizeof(df));
	printf("size of long double float f is %ld\n", sizeof(ldf));

	//+ precision issues
	f = .1 + .1 + .1;
	printf("float f is %1.10f\n", f);
	if (f == 0.3) {
		puts("true");
	}
	else {
		puts("false");
	}


	//++ Characters and Strings
	puts("\n\nCharacters and Strings\n");

	char cstring[] = "String";
	puts(cstring);
	for (unsigned int i = 0; cstring[i]; i++) {
		printf("%02d: %c\n", i, cstring[i]);
	}

	// Escape sequences
	puts("This is a string \\ \' \" \x40 \u03bc");


	//++ Qualifiers
	puts("\n\nQualifiers\n");
	const static int i = 42;
	// const = immutable

	// CV Qualifiers		
	// const				
	// volatile - might be changed by another process
	// mutable		

	// Storage Duration:
	// static
	// extern
	// register

	cout << func() << ", " << func() << ", " << func() << endl;
	

	//++ References
	puts("\n\nReferences\n");
	int a = 5;
	int & ar = a;
	printf("the value is %d\n", ar);
	a = 9;
	printf("the value is %d\n", ar);
	printf("the value is %d\n", refInc(a));
	printf("the value is %d\n", ar);
	printf("the value is %d\n", refIncConst(ar));
	printf("the value is %d\n", ar);

	getchar();
	return 0;
}
