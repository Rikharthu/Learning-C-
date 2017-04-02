#include <iostream>
using namespace std;
#include "vect.h"

Vect::Vect()
{
	cout << "Vect()" << endl;
	size = 16;
	p = new int[size];
}

Vect::Vect(int n)
{		
	cout << "Vect(int)" << endl;
	if ( n <= 0 ){
		cout <<  "Illegal Vect size: " << n << endl;
		exit(1);
	} 
	size = n;
	p = new int[size];
}

Vect::Vect(const Vect& v)
{
	cout << "Vect(Vect&)" << endl;
	size = v.size;
	p = new int[size];
	for( int i = 0; i < size; ++i) p[i] = v.p[i];
}

Vect::Vect(const int a[], int n)
{	
	cout << "Vect(int[],int)" << endl;
	if ( n <= 0 ){
		cout <<  "Illegal Vect size: " << n << endl;
		exit(1);
	} 
	size = n;
	p = new int[size];
	for( int i = 0; i < size; ++i) p[i] = a[i]; 
}

// x[i]
int& Vect::operator [](int i)
{
	cout << "Vect operator []" << endl;
	if ( i < 0 || i > size-1 ){
		cout <<  "Illegal Vect index: " << i << endl;
getchar();
		exit(2);
	} 
	return ( p[i] );
}

Vect& Vect::operator =(const Vect& v)
{
	cout << "Vect operator =" << endl;
	// kadu izmeru mums vajag? (nemam māzāko)
	int s = (size < v.size) ? size : v.size;
	for( int i = 0; i < s; ++i) p[i] = v.p[i];
	return ( *this );
}

void Vect::print(int n)
{
	int s = ( n < size ) ? n : size;
	for( int i = 0; i < s; ++i) cout << p[i] << ' ';
	cout << endl;
}

void Vect::print()
{
	print(size);
}

//! šeit operators ir klases loceklis => pirmais operands bus pats klases objekts, kur izpilda funkciju
Vect& Vect::operator+(int c)
{
	cout << "Vect operator + (int)" << endl;
	for( int i = 0; i < size; ++i) p[i] += c;
	return ( *this );
}

// Šeit operators ir ārēja funkcija (var būt draugs)
// abi operandi ir šis funkcijas parametri
Vect& operator+(int c, Vect& v)
{
	cout << "(ārējais) Vect operator + (int, Vect&)" << endl;
	// will call "Vect& Vect::operator+(int c)"
	v + c;
	return (v);
}

Vect& Vect::operator++()
{
	cout << "Vect operator ++" << endl;
	for (int i = 0; i < size; i++)
      p[i]++;

   return *this;
}
