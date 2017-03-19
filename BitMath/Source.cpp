#include <cstdio>
#include <iostream>
using namespace std;

string toBinary(int a);

// http://playground.arduino.cc/Code/BitMath

int main(int argc, char** argv) {
	// set console color (black background(0), green foreground(A))
	system("Color 0A");

	// Bitwise AND
	puts("Bitwise AND");
	printf("0 & 0 = %d\n", 0 & 0);
	printf("0 & 1 = %d\n", 0 & 1);
	printf("1 & 0 = %d\n", 1 & 0);
	printf("1 & 1 = %d\n", 1 & 1);
	// in C++ int commonly has 16 bits => 16 AND operations will be performed
	int a = 92;    // in binary: 0000000001011100
	int b = 101;    // in binary: 0000000001100101
	int c = a & b;  // result:    0000000001000100, or 68 in decimal.
	printf("%d = %s\n", a, toBinary(a));
	printf("%d & %d = %d\n", a, b, a&c);
	// One of the most common uses of bitwise AND is to select a particular bit 
	// (or bits) from an integer value, often called masking

	// Masking
	// http://sernam.ru/c_17.php
	puts("\nMasking");
	// access the least significant bit in a variable x, and store the bit in another variable y
	int flags = 0;		// binary 00000000
	int mask = 2;		// binary 00000010
	//int y = x & 1;   // now y == 1
	//x = 4;           // binary: 100
	//y = x & 1;       // now y == 0


	// Bitwise OR	
	puts("\nBitwise AND");
	printf("0 | 0 = %d\n", 0 | 0);
	printf("0 | 1 = %d\n", 0 | 1);
	printf("1 | 0 = %d\n", 1 | 0);
	printf("1 | 1 = %d\n", 1 | 1);
	a = 92;    // in binary: 0000000001011100
	b = 101;    // in binary: 0000000001100101
	c = a | b;  // result:    0000000001111101, or 125 in decimal.
	printf("%d = %s\n", a, toBinary(a));
	printf("%d | %d = %d\n", a, b, a | c);
	// Bitwise OR is often used to make sure that given bit is set to 1
	// For example, to copy the bits from a into b, while making sure the lowest bit is set to 1
	a = a | 1; // in binary: 0000000001011101
	printf("a | 1 = %d\n", a);

	// Bitwise XOR
	puts("\nBitwise XOR");
	printf("0 ^ 0 = %d\n", 0 ^ 0);
	printf("0 ^ 1 = %d\n", 0 ^ 1);
	printf("1 ^ 0 = %d\n", 1 ^ 0);
	printf("1 ^ 1 = %d\n", 1 ^ 1);
	int x = 12;     // binary: 1100
	int y = 10;     // binary: 1010
	int z = x ^ y;  // binary: 0110, or decimal 6
	printf("%d ^ %d = %d\n", x, y, z);
	// The ^ operator is often used to toggle (i.e. change from 0 to 1, or 1 to 0) 
	// some of the bits in an integer expression while leaving others alone. 
	y = x ^ 1;   // toggle the lowest bit in x, and store the result in y.
	printf("%d ^ 1 = %d\n", x, y);
	y ^= 1;
	printf("%d ^ 1 = %d\n", y ^ 1, y);
	a = 0xb01101001;
	b = 0b001000100;
	printf("%d", a^b);

	// Bitwise NOT
	puts("\nBitwise XOR");
	a = 103;    // binary:  0000000001100111
	b = ~a;     // binary:  1111111110011000 = -104
	printf("a = %d, b = ~a = %d\n", a, b);
	// note that for any integer x, ~x is the same as -x-1 (due to two's complement)
	x = 15;
	printf("x = %d, ~x = %d, -x-1 = %d\n", x, ~x, -x - 1);

	// Bit Shift Operators
	puts("\nBit Shift Operators");
	a = 5;        // binary: 0000000000000101
	b = a << 3;   // binary: 0000000000101000, or 40 in decimal
	c = b >> 3;   // binary: 0000000000000101, or back to 5 like we started with
	printf("a = %d, b = a << 3 = %d, c = b >> 3 = %d\n", a, b, c);
	// When you shift a value x by y bits (x << y), the leftmost y bits in x are lost, literally shifted out of existence
	a = 5;        // binary: 0000000000000101
	b = a << 14;  // binary: 0100000000000000 - the first 1 in 101 was discarded
	/* Can be used to generate the powers of two
		1 <<  0  ==    1	(00000001)
		1 <<  1  ==    2	(00000010)
		1 <<  2  ==    4	(00000100)
		1 <<  3  ==    8	(00001000)
		...
		1 <<  8  ==  256
		1 <<  9  ==  512
		1 << 10  == 1024
	*/
	/* SIGN EXTENSION: When you shift x right by y bits(x >> y), and the highest bit in x is a 1,
	the behavior depends on the exact data type of x.If x is of type int,
	the highest bit is the sign bit, determining whether x is negative or not,
	as we have discussed above.In that case, the sign bit is copied into lower bits,
	for esoteric historical reasons */
	x = -16;     // binary: 1111111111110000
	y = x >> 3;  // binary: 1111111111111110
	// If you want zeroes to be shifted in from the left, then use unsigned int expressions
	x = -16;				// binary: 1111111111110000
	y = unsigned(x) >> 3;	// binary: 0001111111111110
	// Can be used to divide by powers of 2 (MIND SIGN EXTENSION)
	x = 1000;
	y = x >> 3; // integer division of 1000 by 8 (2^3), causing y = 125;
	printf("%d >> %d = %d\n", x, 3, y);

	getchar();
	return 0;
}

string toBinary(int a) {

	return "NOT IMPLEMENTED";
}